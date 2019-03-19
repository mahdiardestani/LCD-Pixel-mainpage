#include "U8glib.h"


//**************************************************
U8GLIB_SSD1306_128X64 u8g(5, 6, 9, 8, 7);
//**************************************************

void setup() {  
  u8g.setFont(u8g_font_unifont);
  u8g.setColorIndex(1); // Instructs the display to draw with a pixel on. 
}

void loop() {  
  u8g.firstPage();
  do {  
   u8g.drawStr( 0, 10 , "Clean"); 
   u8g.drawLine(0, 32, 4,28);             //left arrow
   u8g.drawLine(0, 32, 4,36);             //left arrow
   u8g.drawFrame(40,21,50,30);            // draw box
   u8g.drawStr( 53, 39 , "Run");
  } while( u8g.nextPage() );
  delay(100);   
}
