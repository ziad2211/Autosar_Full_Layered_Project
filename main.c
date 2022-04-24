/******************************************************************************
 *
 *
 * File Name: main.c
 *
 * Description: source for main program
 *
 * Date: 11 April 2022
 * Author: Ziad Abdallah
 ******************************************************************************/
#include "Test.h"
#include "Os.h"

int main(void)
{
#if (MODULE_TEST == STD_ON)
  /* Run Test Case 1 */
    TestCase1();
    
  /* Run Test Case 2 */  
    TestCase2();
    
  /* Initialize Port Driver */
    Port_Init(&Port_Configuration);
    
  /* Run Test Case 3 */ 
    TestCase3();
    
  /* Run Test Case 4 */ 
    TestCase4();    

  /* Run Test Case 5 */ 
    TestCase5();

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
  /* Run Test Case 6 */ 
    TestCase6();    
#endif /* (PORT_SET_PIN_DIRECTION_API == STD_ON) */
    
#if (PORT_VERSION_INFO_API == STD_ON)    
  /* Run Test Case 7 */ 
    TestCase7();       
#endif /* #if (PORT_VERSION_INFO_API == STD_ON) */
    
#endif /* (MODULE_TEST == STD_ON) */
    
    /*
     * START OS
     */
    Os_start();
}