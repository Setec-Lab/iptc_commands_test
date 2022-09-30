#include <SPI.h>
#include "pins_arduino.h"

void setup (void)
{
  // Put SCK, MOSI, SS pins into output mode
  // also put SCK, MOSI into LOW state, and SS into HIGH state.
  // Then put SPI hardware into Master mode and turn SPI on
  Serial.begin(9600);

  SPI.begin ();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  
}  // end of setup

void loop (void)
{
  bool hello;
  char val;
  uint8_t header[2] = {0x00, 0xFF};
  uint8_t footer[2] = {0xFF, 0x00};


  Serial.print("Presione h para \"Hello\" y b para \"Bye\"")

  val = Serial.read();
  switch (val){
    case 0x68:
      hello = true;
      break;
    case 0x62:
      hello = false;
      break;
  }

  char c;

  print()

  // enable Slave Select
  digitalWrite(SS, LOW);    // SS is pin 10

  // send test string

  SPI.transfer(0x00);
  if(hello){
    SPI.transfer(0x01);
  }else{
    SPI.transfer(0x02);
  }
  SPI.transfer(0xFF);


  // disable Slave Select
  digitalWrite(SS, HIGH);

  delay (5000);  // 1 seconds delay 
}  // end of loop
