/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78
        Device            :  PIC16F18346
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
/*
 Constant Declarations
 */
#define DELAY 13.3333333333
#define PRSR_SNSR_ADDR 0x5D
#define PRSR_H 0x2A
#define PRSR_M 0x29
#define PRSR_L 0x28
#define TMPR_H 0x2C
#define TMPR_L 0x2B
/*
 Global Variables
 */
uint32_t raw_pressure;
uint16_t raw_temperature;
uint8_t value;
static float pressure;
static float temperature;

/*
 
 * Subroutines
 
 */
void setHigh() {
    //set PWM frequency to 9.52kHz
    PWM5CON = 0x80;
    PR2 = 0x68;
    PWM5DCH = 0x34;

}

void setLow() {
    //set PWM frequency to 8.54kHz
    PWM5CON = 0x80;
    PR2 = 0x74;
    PWM5DCH = 0x3A;
}

void setZero() {
    //shutdown PWM
    PWM5CON = 0x00;
}

bool sendPWM(uint8_t *data) {
    uint8_t j = 0;
    //creating a PWM wave in an UART fashion
    setLow();
    __delay_ms(DELAY);
    //    for (i = 0; i < n; i++) { //send_pwm(&dummy_data[i]); 
    for (j = 0; j < 8; j++) {
        (!!((*data >> j)&0x01)) ? setHigh() : setLow();
        __delay_ms(DELAY);
    }
    //    }
    setHigh();
    __delay_ms(DELAY);
    if (*data == 0)return true;
    return false;
    ////////////////////////////////////////////////////////////////////
}

void readPressureSensor() {

    //read pressure registers
    raw_pressure = 0;
    raw_pressure = I2C1_Read1ByteRegister(PRSR_SNSR_ADDR, 0x2A);
    raw_pressure = (raw_pressure << 8) + I2C1_Read1ByteRegister(PRSR_SNSR_ADDR, 0x29);
    raw_pressure = (raw_pressure << 8) + I2C1_Read1ByteRegister(PRSR_SNSR_ADDR, 0x28);

    if (raw_pressure & 0x800000) {
        raw_pressure = (0xff000000 | raw_pressure);
    }
    pressure = (float) (raw_pressure) / 4096.0;
    __delay_ms(500);

    //read temperature registers
    raw_temperature = 0;
    raw_temperature = I2C1_Read1ByteRegister(PRSR_SNSR_ADDR, TMPR_H);
    raw_temperature = (raw_temperature << 8) + I2C1_Read1ByteRegister(PRSR_SNSR_ADDR, TMPR_L);
    temperature = (float) (raw_temperature) / 100.00;

    printf("Pressure : %f\n", pressure);
    printf("Temperature : %f\n", temperature);
}

void sendFloat(float * f) {
    unsigned char **temp = (unsigned char**) &f;
    sendPWM(*temp++);
    sendPWM(*temp++);
    sendPWM(*temp++);
    sendPWM(*temp);
}

/*
                         Main application
 */
void main(void) {
    //initialize the variables
    char hdr_trl[] = {0xFF, 0x00, 0xFF, 0x00};
    // initialize the device
    SYSTEM_Initialize();
    setZero(); //shutdown the PWM
    pressure = 1013.134;
    temperature = 24.76;
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    char dummy_data[] = {0xFF, 0x00, 0xFF, 0x00, 0x16, 'H', 'E', 'L', 'L', 'O', ' ', 'S', 'E', 'N', 'S', 'O', 'R', 'S', 0x17, 0xFF, 0x00, 0xFF, 0x00};
    uint8_t n = sizeof (dummy_data);
    uint8_t i = 0;
    while (1) {
        // Add your application code
        readPressureSensor();
        __delay_ms(1000);
        //        // routine to measure pressure and sensor
        ////        readPsrSnsr();
        //        
        //            printf("Pressure : %f\n",pressure);
        //            printf("Temperature : %f\n",temperature);
        /*The whole sending data sequence through PWM and UART*/
        //keep the PWM on PORTC in high input impedance state
        //        TRISC = 0xFF;
        //        if (PORTCbits.RC4 == 1) {
        //        }//check if button is pressed and start sending
        //        else {
        //            LATCbits.LATC3 = 1; //turn ON LED to indicate transmission
        //            TRISC = 0xBF; //set the PORT C PWM to o/p
        ////            for (i = 0; i < n; i++) {
        ////                sendPWM(&dummy_data[i]);
        ////            }
        //            //start header pwm
        ////            for(i=0;i<4;i++)sendPWM(&hdr_trl[i]);
        //            readPsrSnsr();
        ////            sendFloat(&pressure);
        ////            sendFloat(&temperature);                    
        //            //end trailer pwm
        ////            for(i=0;i<4;i++)sendPWM(&hdr_trl[i]);
        //            //            send_pwm(&i); //make data and send one byte at a time.//sending dummy data now
        //            LATCbits.LATC3 = 0; //turn OFF LED to indicate end
        //            //            printf("%c", 'd'); //send data to UART to test at 1200 baud
        //        }
    }
}
/**
 End of File
 */