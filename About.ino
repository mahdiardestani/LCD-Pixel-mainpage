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
   u8g.drawLine(60, 4, 64, 0);
   u8g.drawLine(64, 0, 68, 4);
   u8g.drawStr( 45, 36 , "About");
   u8g.drawLine(60, 60, 64, 64);
   u8g.drawLine(64, 64, 68, 60);
  } while( u8g.nextPage() );
  delay(100);   
}
