#include <project.h>
#include <stdint.h>

int main(void)
{
    CyGlobalIntEnable; 
    
    
    //Lights both LEDS
    LED_1_Write(1);
    LED_2_Write(1);
    
    //Instantiates the LCD and clears its display
    LCD_Start();
    LCD_ClearDisplay();
    
    //Initializes LCD And Begins to show the first part of the text,
    //delaying to allow the user to read it, clearing the display, and
    //printing the same sentence with the first two letters deleted. 
    //This allows for a scrolling effect
    
    //Scrolls "MY First Microcontroller I/O" across the screen
    LCD_PrintString("My First Microcontroller I/O");
    CyDelay(500);
    LCD_ClearDisplay();
    
        LCD_PrintString(" First Microcontroller I/O");
        CyDelay(500);
        LCD_ClearDisplay();
        
            LCD_PrintString("irst Microcontroller I/O Console");
            CyDelay(500);
            LCD_ClearDisplay();
            
                LCD_PrintString("st Microcontroller I/O Console Program");
                CyDelay(500);
                LCD_ClearDisplay();
                
                    LCD_PrintString(" Microcontroller I/O Console Program");
                    CyDelay(500);
    `               LCD_ClearDisplay();
    
                        LCD_PrintString("icrocontroller I/O Console Program");
                        CyDelay(500);
                        LCD_ClearDisplay();
                        
                            LCD_PrintString("rocontroller I/O Console Program");
                            CyDelay(500);
                            LCD_ClearDisplay();
                            
                                LCD_PrintString("controller I/O Console Program");
                                CyDelay(500);
                                LCD_ClearDisplay();
                                
                                    LCD_PrintString("ntroller I/O Console Program");
                                    CyDelay(500);
                                    LCD_ClearDisplay();
                                    
                                        LCD_PrintString("roller I/O Console Program");
                                        CyDelay(500);
                                        LCD_ClearDisplay();
    
                                            LCD_PrintString("ller I/O Console Program");
                                            CyDelay(500);
                                            LCD_ClearDisplay();
                                            
                                                LCD_PrintString("er I/O Console Program");
                                                CyDelay(500);
                                                LCD_ClearDisplay();
    
                                                    LCD_PrintString(" I/O Console Program");
                                                    CyDelay(500);
                                                    LCD_ClearDisplay();
    
                                                        LCD_PrintString("/O Console Program");
                                                        CyDelay(500);
                                                        LCD_ClearDisplay();
                                                            
                                                            LCD_PrintString(" Console Program");
                                                            CyDelay(500);
                                                            LCD_ClearDisplay();
   
                                                                LCD_PrintString("onsole Program");
                                                                CyDelay(500);
                                                                LCD_ClearDisplay();
    
                                                                    LCD_PrintString("sole Program");
                                                                    CyDelay(500);
                                                                    LCD_ClearDisplay();
                                                                    
                                                                        LCD_PrintString("le Program");
                                                                        CyDelay(500);
                                                                        LCD_ClearDisplay();
    
                                                                            LCD_PrintString(" Program");
                                                                            CyDelay(500);
                                                                            LCD_ClearDisplay();
    
                                                                                LCD_PrintString("rogram");
                                                                                CyDelay(500);
                                                                                LCD_ClearDisplay();
    
                                                                                    LCD_PrintString("gram");
                                                                                    CyDelay(500);
                                                                                    LCD_ClearDisplay();
                                                                                
                                                                                        LCD_PrintString("am");
                                                                                        CyDelay(500);
                                                                                        LCD_ClearDisplay();
    
    //Scrolls "Microcontroller Programmer" across the screen
    
    LCD_PrintString("                        Mi");
    CyDelay(500);
    LCD_ClearDisplay();
    
        LCD_PrintString("                      Micr");
        CyDelay(500);
        LCD_ClearDisplay();
    
            LCD_PrintString("                    Microc");
            CyDelay(500);
            LCD_ClearDisplay();
    
                LCD_PrintString("                  Microcon");
                CyDelay(500);
                LCD_ClearDisplay();
    
                    LCD_PrintString("                Microcontr");
                    CyDelay(500);
                    LCD_ClearDisplay();
    
                        LCD_PrintString("              Microcontrol");
                        CyDelay(500);
                        LCD_ClearDisplay();
    
                            LCD_PrintString("            Microcontrolle");
                            CyDelay(500);
                            LCD_ClearDisplay();
    
                                LCD_PrintString("          Microcontroller ");
                                CyDelay(500);
                                LCD_ClearDisplay();
    
                                    LCD_PrintString("        Microcontroller Pr");
                                    CyDelay(500);
                                    LCD_ClearDisplay();
    
                                        LCD_PrintString("      Microcontroller Prog");
                                        CyDelay(500);
                                        LCD_ClearDisplay();
    
                                            LCD_PrintString("    Microcontroller Progra");
                                            CyDelay(500);
                                            LCD_ClearDisplay();
    
                                                LCD_PrintString("  Microcontroller Programm");
                                                CyDelay(500);
                                                LCD_ClearDisplay();
    
                                                    LCD_PrintString("Microcontroller Programmer");
                                                    CyDelay(500);
                                                    LCD_ClearDisplay();
    
                                                        LCD_PrintString("crocontroller Programmer");
                                                        CyDelay(500);
                                                        LCD_ClearDisplay();
    
                                                            LCD_PrintString("ocontroller Programmer");
                                                            CyDelay(500);
                                                            LCD_ClearDisplay();
    
                                                                LCD_PrintString("ontroller Programmer");
                                                                CyDelay(500);
                                                                LCD_ClearDisplay();
    
                                                                    LCD_PrintString("troller Programmer");
                                                                    CyDelay(500);
                                                                    LCD_ClearDisplay();
    
                                                                        LCD_PrintString("oller Programmer");
                                                                        CyDelay(500);
                                                                        LCD_ClearDisplay();
    
                                                                            LCD_PrintString("ler Programmer");
                                                                            CyDelay(500);
                                                                            LCD_ClearDisplay();
                                                        
                                                                                LCD_PrintString("r Programmer");
                                                                                CyDelay(500);
                                                                                LCD_ClearDisplay();
    
                                                                                    LCD_PrintString("Programmer");
                                                                                    CyDelay(500);
                                                                                    LCD_ClearDisplay();
                                                        
                                                                                        LCD_PrintString("ogrammer");
                                                                                        CyDelay(500);
                                                                                        LCD_ClearDisplay();
                                                    
                                                                                            LCD_PrintString("rammer");
                                                                                            CyDelay(500);
                                                                                            LCD_ClearDisplay();
    
                                                                                                LCD_PrintString("mmer");
                                                                                                CyDelay(500);
                                                                                                LCD_ClearDisplay();
    
                                                                                                    LCD_PrintString("er");
                                                                                                    CyDelay(500);
                                                                                                    LCD_ClearDisplay();
    
    
    // Prints "Tap a switch to" on the first line of the LCD screen
    LCD_PrintString("Tap a switch to");
    
    // Prints "turn off its LED" on the first line of the LCD screen
    LCD_PrintString("                         turn off its LED");
    
    //infinite loop
    for(;;)
        {   
            //if LED_1 is off and the 1st button is pressed, it is turned back on
            //and the LCD screen says "LED 1 Toggled"
            if(LED_1_Read()==0)
                {
                    if(InputPin_1_Read()==0)
                        {
                            LCD_ClearDisplay();
                            LED_1_Write(1);
                            CyDelay(100);
                            LCD_PrintString("LED 1 Toggled");
                            CyDelay(500);
                        }
                }
        
            //if LED_2 is off and the 2nd button is pressed, it is turned back on
            //and the LCD screen says "LED 2 Toggled"
            if(LED_2_Read()==0)
                {
                    if(InputPin_2_Read()==0)
                        {
                            LCD_ClearDisplay();
                            LED_2_Write(1);
                            CyDelay(100);
                            LCD_PrintString("LED 2 Toggled");
                            CyDelay(500);
                        }
                }
                
            //if the 1st button is pressed, LED_1 is turned off 
            //and the LCD screen says "LED 1 Toggled"
            while(InputPin_1_Read()==0)
                {
                    LCD_ClearDisplay();
                    LED_1_Write(0);
                    CyDelay(100);
                    LCD_PrintString("LED 1 Toggled");
                    CyDelay(500);
                }  
            //if the 2nd button is pressed, LED_2 is turned off 
            //and the LCD screen says "LED 2 Toggled"
            while(InputPin_2_Read()==0 )
                {
                    LCD_ClearDisplay();
                    LED_2_Write(0);
                    CyDelay(100);
                    LCD_PrintString("LED 2 Toggled");
                    CyDelay(500);
                }
     
    
        }
}


