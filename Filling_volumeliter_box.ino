#include "U8glib.h"


//**************************************************
U8GLIB_SSD1306_128X64 u8g(5, 6, 3, 8, 7);
//**************************************************

char buff[50];
int value=0;
int curent_page =0;
void pciSetup(byte pin)
{
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
  PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
  PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

ISR (PCINT0_vect){
  // handle pin change interrupt for D
  //button increase     
  if (digitalRead(13)){
    value = value + 1;  
  }
  // buttton decrease
  if(digitalRead(10)){
    value = value - 1;
  }
  //button ok
  if(digitalRead(11)){
   curent_page=1;
  }
}

void change_filling_display(){ 
  u8g.firstPage();
  do{
  u8g.drawStr( 0, 10 , "Filling"); 
  u8g.setColorIndex(1);
  //left arrow          
  u8g.drawLine(0, 32, 4,28);            
  u8g.drawLine(0, 32, 4,36);            
  //draw box
  u8g.drawFrame(18,16,95,40);
  //u8g.drawBox(18,16,95,40);   
  //text 
  u8g.setColorIndex(1);
  u8g.drawStr(42,40," ul" );
  sprintf(buff,"%d",value);
  u8g.drawStr(24,40,buff);
  //vertical Line in box
  u8g.drawLine(90,19,90,55); 
  //horizontal line in box          
  u8g.drawLine(90,37,110,37); 
  //up arrow in box         
  u8g.drawLine(96,28, 100, 24);       
  u8g.drawLine(100, 24, 104, 28); 
  //down arrow in box   
  u8g.drawLine(96, 44, 100, 48);     
  u8g.drawLine(100, 48, 104, 44); 
  }while(u8g.nextPage());
}

void main_filling_display(){
  u8g.firstPage();
  do{
  //text
  u8g.setColorIndex(1);
  u8g.drawStr( 0, 10 , "Filling"); 
  //left arrow          
  u8g.drawLine(0, 32, 4,28);            
  u8g.drawLine(0, 32, 4,36);            
  //draw box
  //u8g.drawFrame(18,16,95,40);
  u8g.drawBox(18,16,95,40);   
  //text 
  u8g.setColorIndex(0);
  u8g.drawStr(42,40," ul" );
  sprintf(buff,"%d",value);
  u8g.drawStr(24,40,buff);
  //vertical Line in box
  u8g.drawLine(90,19,90,55); 
  //horizontal line in box          
  u8g.drawLine(90,37,110,37); 
  //up arrow in box         
  u8g.drawLine(96,28, 100, 24);       
  u8g.drawLine(100, 24, 104, 28); 
  //down arrow in box   
  u8g.drawLine(96, 44, 100, 48);     
  u8g.drawLine(100, 48, 104, 44);    
    }while(u8g.nextPage()); 
}

void setup() {
  u8g.setFont(u8g_font_unifont);
 // u8g.setColorIndex(1);         // Instructs the display to draw with a pixel on. 
  pciSetup(10);
  pciSetup(13);
  pciSetup(11);
 }


void loop() {  
  if(curent_page==0){
  main_filling_display();
  }else{
  change_filling_display();
}
  
}
