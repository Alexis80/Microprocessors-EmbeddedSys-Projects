#include <cydevice_trm.h>
#include <CyLib.h>
#include <isr_2.h>
#include "cyapicallbacks.h"
int volatile timer_flag;

#if !defined(isr_2__REMOVED) /* Check for removal by optimization */

//include and defines code
/* `#START isr_2_intc` */

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
* Function Name: isr_2_Start (starts isr, unchanged from original
*******************************************************************************/
void isr_2_Start(void)
{
    /* For all we know the interrupt is active. */
    isr_2_Disable();

    /* Set the ISR to point to the isr_2 Interrupt. */
    isr_2_SetVector(&isr_2_Interrupt);

    /* Set the priority. */
    isr_2_SetPriority((uint8)isr_2_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_2_Enable();
}


/*******************************************************************************
* Function Name: isr_2_StartEx (sets up interrupt, unchanged code)
*******************************************************************************/
void isr_2_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isr_2_Disable();

    /* Set the ISR to point to the isr_2 Interrupt. */
    isr_2_SetVector(address);

    /* Set the priority. */
    isr_2_SetPriority((uint8)isr_2_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_2_Enable();
}


/*******************************************************************************
* Function Name: isr_2_Stop (stops and removes interrupt (unchanged code)
*******************************************************************************/
void isr_2_Stop(void)
{
    /* Disable this interrupt. */
    isr_2_Disable();

    /* Set the ISR to point to the passive one. */
    isr_2_SetVector(&IntDefaultHandler);
}

/*******************************************************************************
* Function Name: isr_2_Interrupt (default function, unchanged code)
*******************************************************************************/
CY_ISR(isr_2_Interrupt)
{
    #ifdef isr_2_INTERRUPT_INTERRUPT_CALLBACK
        isr_2_Interrupt_InterruptCallback();
    #endif /* isr_2_INTERRUPT_INTERRUPT_CALLBACK */

      //sets timer flag to 1
    /*  Place your Interrupt code here. */
    /* `#START isr_2_Interrupt` */
      timer_flag=1;
    /* `#END` */
}


/*******************************************************************************
* Function Name: isr_2_SetVector (changes isr vector, code unchanged)
*******************************************************************************/
void isr_2_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_2__INTC_NUMBER] = address;
}

/*******************************************************************************
* Function Name: isr_2_GetVector (gets the address of the vector, code unchanged)
*******************************************************************************/
cyisraddress isr_2_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_2__INTC_NUMBER];
}

/*******************************************************************************
* Function Name: isr_2_SetPriority (sets interrupt priority, code unchanged)
*******************************************************************************/

void isr_2_SetPriority(uint8 priority)
{
    *isr_2_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: isr_2_GetPriority (gets interrupt priority, code unchanged)
*******************************************************************************/
uint8 isr_2_GetPriority(void)
{
    uint8 priority;


    priority = *isr_2_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: isr_2_Enable (enables the isr, code unchanged)
*******************************************************************************/
void isr_2_Enable(void)
{
    /* Enable the general interrupt. */
    *isr_2_INTC_SET_EN = isr_2__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_2_GetState (gets state of interrupt, code unchanged) 
*******************************************************************************/
uint8 isr_2_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*isr_2_INTC_SET_EN & (uint32)isr_2__INTC_MASK) != 0u) ? 1u:0u;
}

/*******************************************************************************
* Function Name: isr_2_Disable (disables interrupt, unchanged code)
*******************************************************************************/
void isr_2_Disable(void)
{
    /* Disable the general interrupt. */
    *isr_2_INTC_CLR_EN = isr_2__INTC_MASK;
}

/*******************************************************************************
* Function Name: isr_2_SetPending (puts interrupt into pending state (unchanged code)
*******************************************************************************/
void isr_2_SetPending(void)
{
    *isr_2_INTC_SET_PD = isr_2__INTC_MASK;
}

/*******************************************************************************
* Function Name: isr_2_ClearPending (clears pending interrupt (unchanged code)
*******************************************************************************/
void isr_2_ClearPending(void)
{
    *isr_2_INTC_CLR_PD = isr_2__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */

