#include "pins_arduino.h"

char buf [100];
volatile byte pos;
volatile boolean process_it;
char prev; 
bool command;
bool hello;

void setup (void)
{
  Serial.begin (9600);   // debugging

  // have to send on master in, *slave out*
  pinMode(MISO, OUTPUT);
  
  // turn on SPI in slave mode
  SPCR |= _BV(SPE);
  
  // turn on interrupts
  SPCR |= _BV(SPIE);
  
  pos = 0;
  process_it = false;
}  // end of setup


// SPI interrupt routine
ISR (SPI_STC_vect)
{
byte c = SPDR;

  if(command){
    if(c==0x01){
      hello = true; 
    }else{
      hello = false;
    }
  }
  if(c==0x00 & prev==0xFF){
    command = true;
  }

  prev = c;
}

// main loop - wait for flag set in interrupt routine
void loop (void)
{
  if (hello)
    {
    Serial.println("Hello");
    }else{
      Serial.println("Bye");
    }
    
}  // end of loop
