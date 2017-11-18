//include pins’ .h files so that isr_1 may access them
#include <DIG_IN_PIN.h>
#include <DIG_OUT_PIN.h>
#include <cydevice_trm.h>
#include <CyLib.h>
#include <isr_1.h>
#include "cyapicallbacks.h"

#if !defined(isr_1__REMOVED) /* Check for removal by optimization */

// start and definition codes
/* `#START isr_1_intc` */
uint32 volatile int_count =0;
/* `#END` */

#ifndef CYINT_IRQ_BASE
#define CYINT_IRQ_BASE      16
#endif /* CYINT_IRQ_BASE */
#ifndef CYINT_VECT_TABLE
#define CYINT_VECT_TABLE    ((cyisraddress **) CYREG_NVIC_VECT_OFFSET)
#endif /* CYINT_VECT_TABLE */

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: isr_1_Start (starts isr, unchanged from original
*******************************************************************************/
void isr_1_Start(void)
{
    /* For all we know the interrupt is active. */
    isr_1_Disable();

    /* Set the ISR to point to the isr_1 Interrupt. */
    isr_1_SetVector(&isr_1_Interrupt);

    /* Set the priority. */
    isr_1_SetPriority((uint8)isr_1_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_1_Enable();
}


/*******************************************************************************
* Function Name: isr_1_StartEx (sets up interrupt, unchanged code)
*******************************************************************************/
void isr_1_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isr_1_Disable();

    /* Set the ISR to point to the isr_1 Interrupt. */
    isr_1_SetVector(address);

    /* Set the priority. */
    isr_1_SetPriority((uint8)isr_1_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_1_Enable();
}


/*******************************************************************************
* Function Name: isr_1_Stop (stops and removes interrupt (unchanged code)
*******************************************************************************/
void isr_1_Stop(void)
{
    /* Disable this interrupt. */
    isr_1_Disable();

    /* Set the ISR to point to the passive one. */
    isr_1_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: isr_1_Interrupt (default function)
*******************************************************************************/
CY_ISR(isr_1_Interrupt)
{
    #ifdef isr_1_INTERRUPT_INTERRUPT_CALLBACK
        isr_1_Interrupt_InterruptCallback();
    #endif /* isr_1_INTERRUPT_INTERRUPT_CALLBACK */

      //reading and writing the pins within the isr
    /*  Place your Interrupt code here. */
    /* `#START isr_1_Interrupt` */
    DIG_IN_PIN_Read() ;
    DIG_OUT_PIN_Write(DIG_IN_PIN_Read()) ;
    ++ int_count;
    DIG_IN_PIN_ClearInterrupt();
    /* `#END` */
}


/*******************************************************************************
* Function Name: isr_1_SetVector (changes isr vector, code unchanged)
*******************************************************************************/
void isr_1_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_1__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: isr_1_GetVector (gets the address of the vector, code unchanged)
*******************************************************************************/
cyisraddress isr_1_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_1__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: isr_1_SetPriority (sets interrupt priority, code unchanged)
*******************************************************************************/
void isr_1_SetPriority(uint8 priority)
{
    *isr_1_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: isr_1_GetPriority (gets interrupt priority, code unchanged)
*******************************************************************************/
uint8 isr_1_GetPriority(void)
{
    uint8 priority;


    priority = *isr_1_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: isr_1_Enable (enables the isr, code unchanged)
*******************************************************************************/
void isr_1_Enable(void)
{
    /* Enable the general interrupt. */
    *isr_1_INTC_SET_EN = isr_1__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_1_GetState (gets state of interrupt, code unchanged) 
*******************************************************************************/
uint8 isr_1_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*isr_1_INTC_SET_EN & (uint32)isr_1__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: isr_1_Disable (disables interrupt, unchanged code)
*******************************************************************************/
void isr_1_Disable(void)
{
    /* Disable the general interrupt. */
    *isr_1_INTC_CLR_EN = isr_1__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_1_SetPending (puts interrupt into pending state (unchanged code)
*******************************************************************************/
void isr_1_SetPending(void)
{
    *isr_1_INTC_SET_PD = isr_1__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_1_ClearPending (clears pending interrupt (unchanged code)
*******************************************************************************/
void isr_1_ClearPending(void)
{
    *isr_1_INTC_CLR_PD = isr_1__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
