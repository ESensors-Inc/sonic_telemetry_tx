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
#define DATA_SIZE 9
/*
 Global Variables
 */
uint32_t raw_pressure;
uint16_t raw_temperature;
uint8_t value;
static float pressure;
static float temperature;
unsigned char packet[DATA_SIZE];

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
    raw_pressure = I2C1_Read1ByteRegister(PRSR_SNSR_ADDR, PRSR_H);
    packet[0] = raw_pressure;
    raw_pressure = (raw_pressure << 8) + I2C1_Read1ByteRegister(PRSR_SNSR_ADDR, PRSR_M);
    packet[1] = (0x0f & raw_pressure);
    raw_pressure = (raw_pressure << 8) + I2C1_Read1ByteRegister(PRSR_SNSR_ADDR, PRSR_L);
    packet[2] = (0x0f & raw_pressure);
    if (raw_pressure & 0x800000) {
        raw_pressure = (0xff000000 | raw_pressure);
    }
    pressure = (float) (raw_pressure) / 4096.0;
    __delay_ms(500);

    //read temperature registers
    raw_temperature = 0;
    raw_temperature = I2C1_Read1ByteRegister(PRSR_SNSR_ADDR, TMPR_H);
    packet[3] = (0x0f & raw_temperature);
    raw_temperature = (raw_temperature << 8) + I2C1_Read1ByteRegister(PRSR_SNSR_ADDR, TMPR_L);
    packet[4] = (0x0f & raw_temperature);
    temperature = (float) (raw_temperature) / 100.00;

    printf("Pressure : %f\n", pressure);
    printf("Temperature : %f\n", temperature);
}

void sendFloat(float * f) {
    unsigned char **temp = &f;
    sendPWM((*temp)++);
    sendPWM((*temp)++);
    sendPWM((*temp)++);
    sendPWM(*temp);
}

/*
                         Main application
 */
void main(void) {
    //initialize the variables
    char hdr_trl[] = {0xFF, 0x00, 0xFF, 0x00};
    char SOC = 0x16;
    char EOC = 0x17;
    // initialize the device
    SYSTEM_Initialize();
    setZero(); //shutdown the PWM
//    CS_SetHigh();
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
    packet[5] = 'D';
    packet[6] = 'A';
    packet[7] = 'T';
    packet[8] = 'A';
    while (1) {
        // Add your application code        

        /*The whole sending data sequence through PWM and UART*/
        //keep the PWM on PORTC in high input impedance state
        TRISC = 0xDD;        
        if (SWITCH_GetValue() == 1) {
        }//check if button is pressed and start sending
        else {
            // routine to measure pressure and sensor
            readPressureSensor();
            __delay_ms(500);
            LED_SetHigh(); //turn ON LED to indicate transmission
            TRISC = 0x9D; //set the PORT C PWM to o/p
            /*DATA EXPERIMENTS START*/
            
//            for (i = 0; i < n; i++) {
//                sendPWM(&dummy_data[i]);
//            }
//            printf("Hello testing\n");  
            for(i=0;i<4;++i){
                sendPWM(&hdr_trl[i]);
            }
            sendPWM(&SOC);
//            sendFloat(&pressure); 
            for (i=0;i<9;++i){
                sendPWM(&packet[i]);
            }
            sendPWM(&EOC);
            for(i=0;i<4;++i){
                sendPWM(&hdr_trl[i]);
            }
            /*DATA EXPERIMENTS END*/
            
            LED_SetLow(); //turn OFF LED to indicate end
        }
    }
}
/**
 End of File
 */