#include "U8glib.h"


//**************************************************
U8GLIB_SSD1306_128X64 u8g(5, 6, 3, 8, 7);
//**************************************************

void setup() {  
  u8g.setFont(u8g_font_unifont);
  u8g.setColorIndex(1); // Instructs the display to draw with a pixel on. 
}

void loop() {  
  u8g.firstPage();
  u8g.firstPage();
  do{
   //text 
   u8g.drawStr( 0, 10 , "Filling"); 
   //up arrow
   u8g.drawLine(60, 4, 64, 0);               
   u8g.drawLine(64, 0, 68, 4);  
   //down arrow            
   u8g.drawLine(60, 60, 64, 64);           
   u8g.drawLine(64, 64, 68, 60); 
   //left arrow         
   u8g.drawLine(0, 32, 4,28);            
   u8g.drawLine(0, 32, 4,36); 
   // draw box          
   u8g.drawFrame(40,21,50,30); 
   //text           
   u8g.drawStr( 53, 39 , "Run");  
   //animation
   
  }while(u8g.nextPage());
   delay(100);   
}
 
