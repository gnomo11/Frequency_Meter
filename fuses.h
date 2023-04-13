
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#pragma config PLLDIV = 2 
#pragma config CPUDIV = OSC1_PLL2 
#pragma config USBDIV = 1       
#pragma config FOSC = HSPLL_HS 
#pragma config FCMEN = OFF      
#pragma config IESO = OFF       
#pragma config PWRT = ON        
#pragma config BOR = OFF        
#pragma config BORV = 3         
#pragma config VREGEN = OFF     
#pragma config WDT = OFF        
#pragma config WDTPS = 32768    
#pragma config CCP2MX = ON      
#pragma config PBADEN = OFF      
#pragma config LPT1OSC = OFF    
#pragma config MCLRE = ON       
#pragma config STVREN = ON      
#pragma config LVP = OFF        
#pragma config ICPRT = OFF      
#pragma config XINST = OFF      
#pragma config CP0 = OFF        
#pragma config CP1 = OFF        
#pragma config CP2 = OFF       
#pragma config CP3 = OFF        
#pragma config CPB = OFF      
#pragma config CPD = OFF        
#pragma config WRT0 = OFF      
#pragma config WRT1 = OFF      
#pragma config WRT2 = OFF      
#pragma config WRT3 = OFF      
#pragma config WRTC = OFF      
#pragma config WRTB = OFF       
#pragma config WRTD = OFF       
#pragma config EBTR0 = OFF      
#pragma config EBTR1 = OFF     
#pragma config EBTR2 = OFF      
#pragma config EBTR3 = OFF      
#pragma config EBTRB = OFF 


#include <xc.h> // include processor files - each processor file is guarded.  

#endif	/* XC_HEADER_TEMPLATE_H */

