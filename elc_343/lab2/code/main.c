
#include <project.h>

int main()
{
    CyGlobalIntEnable; 

    //infinite loop that produces a square wave

    for(;;)
    {   
        //PART 2 CODE
        
        //Pin_2=button so when the button is pressed
        //Pin_3 (LED2) goes off since the circuit is pulled 
        //up and the circuit is disconnected
        Pin_3_Write(Pin_2_Read());
        
        //PART 1 CODE 
        
        //Sets Pin_1(LED1) to one and then sets it off for 500 ms
        Pin_1_Write(1);
        CyDelay(500);
        //Sets Pin_1(LED1) to zero and then sets it off for 500 ms
        Pin_1_Write(0);
        CyDelay(500);
        
    }
}


