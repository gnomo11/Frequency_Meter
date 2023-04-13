/*
 * File:   ccp_capture.c
 * Author: noel_
 *
 * Created on 26 de julio de 2021, 02:42 PM
 */

#define _XTAL_FREQ 48000000
#include <xc.h>
#include <stdio.h>
#include <pic18f4550.h>
#include "fuses.h"
#include "lcd.h"


void config_interrupts(void);
void config_timer1(void);
void config_ccp1(void);
void tmr1_init(void);

char buffer[16];
float T = 0.0,F=0.0,ticks_f=0.0;
unsigned int ticks=0;

void main(void) {
    
    ADCON1=0x0F;//only digital pins
    config_interrupts();
    config_timer1();
    config_ccp1();
    tmr1_init();
    
    TRISD=0x00;
    lcd_init();
    lcd_clear();
    __delay_ms(10);
    lcd_gotoxy(1,1);
    lcd_write_string("Frecuencia= ");
    
    
    while(1){
        lcd_gotoxy(2,1);
        sprintf(buffer,"%.3f",F);
        lcd_write_string(buffer);
    }
    
    return;
}

void config_interrupts(void){
    INTCONbits.GIE=1;//Enable Global Interrupts
    INTCONbits.PEIE=1; //Enable Peripheral Interrupts
    
    PIE1bits.CCP1IE=1; //Enable the CCP1 interrupt
    PIR1bits.CCP1IF=0; //clear ccp1 interrupt flag
}

void config_timer1(void){

    T1CONbits.RD16=1; //1 operation of 16 bits
    T1CONbits.T1CKPS=0b11; //prescaler 1:8
    T1CONbits.TMR1CS=0; //Fosc/4
    TMR1H=0;TMR1L=0;
}

void config_ccp1(void){
    CCP1CONbits.CCP1M=0b0110;
}

void tmr1_init(void){
    T1CONbits.TMR1ON=1;
}

/*
 T --> Periodo
 * 
 *  T = (4/FOSC)*pres*#ticks
 * donde ticks = cuántos ticks se tarda de un flanco de cambio a otro
 */
void __interrupt()captura(void){
    
    if(PIR1bits.CCP1IF){
        ticks = CCPR1H << 8 | CCPR1L;
        TMR1H=0;TMR1L=0;
        ticks_f = (float)ticks; 
        T = 0.000000667*ticks;
        F = 4.0/T;
        PIR1bits.CCP1IF=0;
    }
    
}