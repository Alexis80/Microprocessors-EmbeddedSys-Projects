/*=======================================
Lexi Adie and Madie Mastroberte
ELC 411
Dr. Pearlstein
Design Assignment 1
*======================================*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>


// Macro which holds the register address
#define NVIC_CPUID_BASE_ADDR (0xe000ed00)


int main(void)

{  
  
       // Declares the 32 bit unsigned integers
       uint32_t implementer;
       uint32_t variant;
       uint32_t partno;
       uint32_t constant;
       uint32_t revision;
       uint32_t reg_val;
  
       // Declares a pointer to a volatile unsigned integer
       uint32_t volatile *my_reg_ptr;
  
       // Puts the value of the pointer into reg val
       reg_val = *my_reg_ptr;
  
       // Access and Extract Register

       //Take values of registers and stores them into corresponding variables

        implementer = (reg_val >> 24) & 0xFF;
        variant     = (reg_val >> 20) & 0xF;
        constant    = (reg_val >> 16) & 0xF;
        partno      = (reg_val >> 04) & 0xFFF;
        revision    = (reg_val >> 00) & 0xF;

        //Manipulate Character String
        //Bubble sort
    
         char myname[] =  "Alexis Kathleen Adie";
    
         int size = sizeof(myname)/sizeof(char);

         for (int i = 0; i < size-1; i++)
         {
             if (myname[i] > myname[i+1])
                 {
                 // Compares the letter to the one before it and flips the two if     
                 // the letter has a higher code
                 char temp = myname[i+1];
                 myname[i+1] = myname[i];
                 myname[i] = temp;

                 // Resets
                 i = -1;
                 }
         }
}







