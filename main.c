/*******************************************************************************
USE TWO 74HC595 AND SOME 2803 TO DRIVE A VFD
ITS A HACK.
*******************************************************************************/
 
/*






0   rxd    rxd
1   txd    txd

2   pd2    
3   pd3    
4   pd4    
5   pd5   
6   pd6    
7   pd7   

8   pb0    
9   pb1   
10  pb2    
11  pb4
12  pb3
13  pb5


A0  pc0    DATA LINE
A1  pc1    DATA CLOCK
A2  pc2    OUTPUT STROBE
A3  pc3   
A4  pc4    
A5  pc5    


A6  adc6
A7  adc7



*/


// manual port D bits 2 to 7


#include <avr/io.h>
#include "7seg.h"


#define OUTPUT             1
#define INPUT              0



  #define SetBit(BIT, PORT)     PORT |= (1<<BIT)
  #define ClearBit(BIT, PORT)   PORT &= ~(1<<BIT)
  #define IsHigh(BIT, PORT)    (PORT & (1<<BIT)) != 0
  #define IsLow(BIT, PORT)     (PORT & (1<<BIT)) == 0
  #define NOP()                 asm volatile ("nop"::)

  // Bit positions, PORTD 
  #define DATA             0
  #define SCLK             1
  #define STB              2


  #define DATAlow()              ClearBit(DATA, PORTC)
  #define SCLKlow()              ClearBit(SCLK, PORTC)
  #define STBlow()               ClearBit(STB, PORTC)

  
  #define DATAhigh()             SetBit(DATA, PORTC)
  #define SCLKhigh()             SetBit(SCLK, PORTC)
  #define STBhigh()              SetBit(STB, PORTC)


  #define pulseSCK()            SCLKlow(); NOP(); NOP(); SCLKhigh(); NOP()
  #define pulseSTB()            STBhigh(); NOP(); NOP(); STBlow()
  
  #define SendOne()             DATAhigh(); pulseSCK()
  #define SendZero()            DATAlow();  pulseSCK()
  
//  void presend8 (unsigned int bits) ;
  void send8 (unsigned int bits, unsigned char latch);
  void Delay(unsigned int delay) ;
  void Delay2(unsigned int delay) ;


int main (void) {

  unsigned int i = 2000;
  
  uint8_t message[] = ":::ONE:IS:THE:LONELIEST:NUNBER:YOULL:DO::::::::::";
  #define msglen 46
  uint8_t offset = 0;
  
  uint8_t DD[5] = {':', ':', ':', ':', ':'};
  

  // set up directions 
  DDRB = (INPUT << PB0 | INPUT << PB1 |INPUT << PB2 |INPUT << PB3 |INPUT << PB4 |INPUT << PB5 |INPUT << PB6 |INPUT << PB7);
  DDRC = (OUTPUT << PC0 | OUTPUT << PC1 |OUTPUT << PC2 |INPUT << PC3 |INPUT << PC4 |INPUT << PC5 |INPUT << PC6 );
  DDRD = (INPUT << PD0 | INPUT << PD1 |INPUT << PD2 |INPUT << PD3 |INPUT << PD4 |INPUT << PD5 |INPUT << PD6 |INPUT << PD7);              
  
  Delay2(4);  
      
  while(1){
    // send8(~segments); send8(digits);               
    // do scanning 
    send8(~CG2[DD[0]-0x30], 0); send8(~0x01, 1);
    Delay(60);
    send8(~CG2[DD[1]-0x30], 0); send8(~0x02, 1);
    Delay(60);
    send8(~CG2[DD[2]-0x30], 0); send8(~0x04, 1);
    Delay(60);
    send8(~CG2[DD[3]-0x30], 0); send8(~0x08, 1);
    Delay(60);
    send8(~CG2[DD[4]-0x30], 0); send8(~0x10, 1);
    Delay(60);
    
    // do scrolling stuffs
    i--;
    if (i == 0) {
    i = 1000;
      offset++;
      if ((offset%msglen)==0) offset = 0;            
      DD[0] = message[offset%msglen];      
      DD[1] = message[(offset+1)%msglen];      
      DD[2] = message[(offset+2)%msglen];      
      DD[3] = message[(offset+3)%msglen];      
      DD[4] = message[(offset+4)%msglen];       
       
    }
  }

}



// send a 8bit word, msb first
void send8 (unsigned int bits, unsigned char latch) {
  uint8_t temp;  
  for( temp = (0x01); temp != 0; temp <<= 1) {    
    if ( (bits & temp) != 0 ) {    SendOne();
    } else {                       SendZero();
    }    
  } 
  if (latch) { pulseSTB(); }
}

/*
void presend8 (unsigned int bits) {
  uint8_t temp;  
  for( temp = (0x01); temp != 0; temp <<= 1) {    
    if ( (bits & temp) != 0 ) {    SendOne();
    } else {                       SendZero();
    }    
  }   
}
*/

void Delay(unsigned int delay) {
  unsigned int x;
  for (x = delay; x != 0; x--) {
    asm volatile ("nop"::); 
  }
}

void Delay2(unsigned int delay) {
  unsigned int x;
  for (x = delay; x != 0; x--) {
    Delay(65000);
  }
}


































