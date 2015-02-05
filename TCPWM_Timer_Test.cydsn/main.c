/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

/*******************************************************************************
* Define Interrupt service routine and allocate an vector to the Interrupt
********************************************************************************/
CY_ISR(InterruptHandler)
{
    Sampling_Timer_ClearInterrupt(Sampling_Timer_INTR_MASK_TC);
    Timer_Out_PIN_Write(1u);
    Timer_Out_PIN_Write(0u);
}

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    CyDelay(50u);
    
    CyGlobalIntEnable;
    
    Timer_ISR_StartEx(InterruptHandler);
    
    Sampling_Timer_Start();
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
