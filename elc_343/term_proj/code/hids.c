#include "common.h"
#include "hids.h"

uint16 mouseSimulation;
uint8 protocol = CYBLE_HIDS_PROTOCOL_MODE_REPORT;   /* Boot or Report protocol mode */
uint8 suspend = CYBLE_HIDS_CP_EXIT_SUSPEND;         /* Suspend to enter into deep sleep mode */

//An event callback function to receive service specific events from HID service

void HidsCallBack(uint32 event, void *eventParam)
{
    CYBLE_HIDS_CHAR_VALUE_T *locEventParam = (CYBLE_HIDS_CHAR_VALUE_T *)eventParam;

    switch(event)
    {
        case CYBLE_EVT_HIDSS_NOTIFICATION_ENABLED:
        
            //enables mousesimulation
            if(CYBLE_HUMAN_INTERFACE_DEVICE_SERVICE_INDEX == locEventParam->serviceIndex)
            {
                mouseSimulation = ENABLED;
            }
            break;
        case CYBLE_EVT_HIDSS_NOTIFICATION_DISABLED:
            //disables mousesimulation
            if(CYBLE_HUMAN_INTERFACE_DEVICE_SERVICE_INDEX == locEventParam->serviceIndex)
            {
                mouseSimulation = DISABLED;
            }
            break;
    }
}

//initializes HID
void HidsInit(void)
{
    CYBLE_API_RESULT_T apiResult;
    uint16 cccdValue;
    
    /* Register service specific callback function */
    CyBle_HidsRegisterAttrCallback(HidsCallBack);
    /* Read CCCD configurations from flash */
    mouseSimulation = DISABLED;
    apiResult = CyBle_HidssGetCharacteristicDescriptor(CYBLE_HUMAN_INTERFACE_DEVICE_SERVICE_INDEX, 
        CYBLE_HUMAN_INTERFACE_DEVICE_REPORT_IN, CYBLE_HIDS_REPORT_CCCD, CYBLE_CCCD_LEN, (uint8 *)&cccdValue);
    if((apiResult == CYBLE_ERROR_OK) && (cccdValue != 0u))
    {
        mouseSimulation |= ENABLED;
    }
    apiResult = CyBle_HidssGetCharacteristicDescriptor(CYBLE_HUMAN_INTERFACE_DEVICE_SERVICE_INDEX, 
        CYBLE_HIDS_BOOT_MOUSE_IN_REP, CYBLE_HIDS_REPORT_CCCD, CYBLE_CCCD_LEN, (uint8 *)&cccdValue);
    if((apiResult == CYBLE_ERROR_OK) && (cccdValue != 0u))
    {
        mouseSimulation |= ENABLED;
    }
}

//Simulates mouse by taking in sensor movements
void SimulateMouse(void)
{   //mouse array
    uint8 abMouseData[MOUSE_DATA_LEN] = {0, 0, 0};  
    //left button variable 
    static uint8 leftButtonPress = 0;               
    CYBLE_API_RESULT_T apiResult;
    //X and Y movement variables
    signed char bX = 0;                          
    signed char bY = 0;                          

    //starts capsense component
    CapSense_Start();
    //initializes sensor baselines
    CapSense_InitializeAllBaselines();
    
    //sensors have long scan cycles so must be enabled
    CapSense_EnableSensor(CapSense_SENSOR_PS1__BTN);
    CapSense_EnableSensor(CapSense_SENSOR_PS2__BTN);
    CapSense_EnableSensor(CapSense_SENSOR_PS3__BTN);
    CapSense_EnableSensor(CapSense_SENSOR_PS4__BTN);
        
    //if the BLE stack is free, simulate mouse
    if(CyBle_GattGetBusyStatus() == CYBLE_STACK_STATE_FREE)
    { 
        while(1u){leftButtonPress = (SW2_Read() == 0u) ? 1u : 0u;
     
        Simulation_LED_Write(LED_ON);
        
        // Check whether the scanning of all enabled widgets is completed. 
        if(0u == CapSense_IsBusy())
        {
            // Update all baselines 
            CapSense_UpdateEnabledBaselines();

            // Start scanning all enabled sensors 
            CapSense_ScanEnabledWidgets();
        }
  
        //checks if each sensor is active, and if it is the cursor moves
        //in direction assigned to the sensor
        //also turns on corresponding led
        if(CapSense_CheckIsSensorActive(CapSense_SENSOR_PS3__BTN ))
        {
            bX = 0;
            bY = CURSOR_STEP;
            LED_DOWN_Write(0);
        }
        
        else if(CapSense_CheckIsSensorActive(CapSense_SENSOR_PS1__BTN))
        {   
            bX = -CURSOR_STEP;
            bY = 0;
            LED_LEFT_Write(0);
        }
    
        else if(CapSense_CheckIsSensorActive(CapSense_SENSOR_PS4__BTN))
        {       
            bX = 0;
            bY = -CURSOR_STEP;
            LED_UP_Write(0); 
        }
        
        else if(CapSense_CheckIsSensorActive(CapSense_SENSOR_LINEARSLIDER0_E0__LS)||
        CapSense_CheckIsSensorActive(CapSense_SENSOR_LINEARSLIDER0_E0__LS))
        // if right sensor was working : else if(CapSense_CheckIsSensorActive(CapSense_SENSOR_PS2__BTN))
        {      
            bX = CURSOR_STEP;
            bY = 0;
            LED_RIGHT_Write(0); 
        }
  
        //resets LEDs once button is no longer pressed
        LED_UP_Write(LED_OFF);
        LED_DOWN_Write(LED_OFF);
        LED_RIGHT_Write(LED_OFF);
        LED_LEFT_Write(LED_OFF);  
 
    
        //loads values into mouse array for x, y, and left button click
        abMouseData[1u] = bX;                            
        abMouseData[2u] = bY;
        abMouseData[0u] = (leftButtonPress ? MOUSE_LB : 0u);     
    
    
        //BLE component processes events
        CyBle_ProcessEvents();
        
        apiResult = CyBle_HidssSendNotification(cyBle_connHandle, CYBLE_HUMAN_INTERFACE_DEVICE_SERVICE_INDEX, 
        CYBLE_HUMAN_INTERFACE_DEVICE_REPORT_IN, MOUSE_DATA_LEN, abMouseData);
       
        //resets X and Y as soon as movement is completed
        bY=0;
        bX=0;
        Simulation_LED_Write(LED_OFF);
        }
        
    }

}
