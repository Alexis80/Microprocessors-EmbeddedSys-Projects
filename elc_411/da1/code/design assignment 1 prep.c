// NOTE: I un-indented a fair amount of code ...


#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdint.h>

//macro which holds the register address
#define NVIC_CPUID_BASE_ADDR (0xe000ed00)

int main(void) 
{   
    //declares the 32 bit unsigned integers
    uint32_t implementer;
    uint32_t variant;
    uint32_t partno;
    uint32_t revision;
    uint32_t reg_val;
    
    //declares a pointer to a volatile unsigned integer
    uint32_t volatile *my_reg_ptr;
    
    //make the pointer point to NVIC_CPUID_BASE_ADDR register
    my_reg_ptr = ( uint32_t *) NVIC_CPUID_BASE_ADDR;
    
    //puts the value of the pointer into reg val
    reg_val = *my_reg_ptr;
    
    // Access and Extract Register 
        
    //take the values of the register and stores them into
    //corresponding varaibles.
    implementer = (reg_val >> 24) & 0xFF;
    variant     = (reg_val >> 20);
    partno      = (reg_val >> 04);
    revision    = (reg_val >> 00);
        
    // Manipulate Char String
        
    //declares char string for 4.2
    char myname[] = "Alexis Kathleen Adie";
    int n,j,k;
    char temp;
           
    //bubble sort
    for(j=1; j<n; j++)
    {
        for(k=0; k<n-j; k++)
        {
            if((int)myname[k]>=(int)myname[k+1])
            {
                temp=myname[k];
                myname[k]=myname[k+1];
                myname[k+1]=temp;
            }
        }
    }
}
