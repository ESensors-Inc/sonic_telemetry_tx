/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78
        Device            :  PIC16F18346
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA2
#define LED_LAT                  LATAbits.LATA2
#define LED_PORT                 PORTAbits.RA2
#define LED_WPU                  WPUAbits.WPUA2
#define LED_OD                   ODCONAbits.ODCA2
#define LED_ANS                  ANSELAbits.ANSA2
#define LED_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_GetValue()           PORTAbits.RA2
#define LED_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set SWITCH aliases
#define SWITCH_TRIS                 TRISAbits.TRISA4
#define SWITCH_LAT                  LATAbits.LATA4
#define SWITCH_PORT                 PORTAbits.RA4
#define SWITCH_WPU                  WPUAbits.WPUA4
#define SWITCH_OD                   ODCONAbits.ODCA4
#define SWITCH_ANS                  ANSELAbits.ANSA4
#define SWITCH_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define SWITCH_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define SWITCH_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define SWITCH_GetValue()           PORTAbits.RA4
#define SWITCH_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define SWITCH_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define SWITCH_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define SWITCH_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define SWITCH_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define SWITCH_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define SWITCH_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define SWITCH_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set CS aliases
#define CS_TRIS                 TRISCbits.TRISC1
#define CS_LAT                  LATCbits.LATC1
#define CS_PORT                 PORTCbits.RC1
#define CS_WPU                  WPUCbits.WPUC1
#define CS_OD                   ODCONCbits.ODCC1
#define CS_ANS                  ANSELCbits.ANSC1
#define CS_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define CS_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define CS_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define CS_GetValue()           PORTCbits.RC1
#define CS_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define CS_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define CS_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define CS_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define CS_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define CS_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define CS_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set VDS aliases
#define VDS_TRIS                 TRISCbits.TRISC5
#define VDS_LAT                  LATCbits.LATC5
#define VDS_PORT                 PORTCbits.RC5
#define VDS_WPU                  WPUCbits.WPUC5
#define VDS_OD                   ODCONCbits.ODCC5
#define VDS_ANS                  ANSELCbits.ANSC5
#define VDS_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define VDS_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define VDS_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define VDS_GetValue()           PORTCbits.RC5
#define VDS_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define VDS_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define VDS_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define VDS_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define VDS_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define VDS_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define VDS_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define VDS_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/