#include "common.h"
#include "hids.h"

uint16 connIntv = CYBLE_GAPP_CONNECTION_INTERVAL_MIN;  
uint8 authenticated = 0u;

//callback to receive events from BLE component
void AppCallBack(uint32 event, void* eventParam)
{
    CYBLE_API_RESULT_T apiResult;
    CYBLE_GAP_BD_ADDR_T localAddr;
    CYBLE_GAP_AUTH_INFO_T *authInfo;
    
    switch (event)
	{
        /**********************************************************
        *                       General Events
        ***********************************************************/
		case CYBLE_EVT_STACK_ON: /* This event received when component is Started */
            /* Enter into discoverable mode so that remote can search it. */
            apiResult = CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
            Advertising_LED_Write(LED_ON);
            localAddr.type = 0u;
            CyBle_GetDeviceAddress(&localAddr);
			break;
            
        /**********************************************************
        *                       GAP Events
        ***********************************************************/
        case CYBLE_EVT_GAP_AUTH_COMPLETE:
            authInfo = (CYBLE_GAP_AUTH_INFO_T *)eventParam;
            (void)authInfo;
            authenticated = 1;
            break;
        case CYBLE_EVT_GAP_DEVICE_CONNECTED:
            Advertising_LED_Write(LED_OFF);
            connIntv = ((CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T *)eventParam)->connIntv * 5u /4u;
            break;
        case CYBLE_EVT_GAPC_CONNECTION_UPDATE_COMPLETE:
            connIntv = ((CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T *)eventParam)->connIntv * 5u /4u;
            break;
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
            apiResult = CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
            break;

        /**********************************************************
        *                       GATT Events
        ***********************************************************/
        case CYBLE_EVT_GATT_CONNECT_IND:
            HidsInit();
            break;
	}
}

int main()
{
    CYBLE_API_RESULT_T apiResult;
    CYBLE_STACK_LIB_VERSION_T stackVersion;
    
    CyGlobalIntEnable;  
    
    Disconnect_LED_Write(LED_OFF);
    Advertising_LED_Write(LED_OFF);
    Simulation_LED_Write(LED_OFF);

    // Start CYBLE component and register generic event handler 
    apiResult = CyBle_Start(AppCallBack);
    apiResult = CyBle_GetStackLibraryVersion(&stackVersion);

    //turn off all leds
    LED_UP_Write(1);
    LED_DOWN_Write(1);
    LED_RIGHT_Write(1);
    LED_LEFT_Write(1);
    
	while(1) 
    {              
        //BLE processes pending events
        CyBle_ProcessEvents();

        //ensures ble component is connected and that mousesim is enabled
        if((CyBle_GetState() == CYBLE_STATE_CONNECTED) && (suspend != CYBLE_HIDS_CP_SUSPEND) && (authenticated !=0u))
        {
                if(mouseSimulation == ENABLED)
                {
                    SimulateMouse();
                }
        }
    
    }
}
