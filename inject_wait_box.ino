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
   u8g.drawStr( 0, 10 , "Inject"); 
   //make arrows
   u8g.drawLine(60, 4, 64, 0);              //up arrow
   u8g.drawLine(64, 0, 68, 4);             //up arrow
   u8g.drawLine(60, 60, 64, 64);          //down arrow
   u8g.drawLine(64, 64, 68, 60);         //down arrow
   u8g.drawLine(0, 32, 4,28);           //left arrow
   u8g.drawLine(0, 32, 4,36);          //left arrow
   //end
   u8g.drawFrame(62,18,60,25);        //draw box1 
   u8g.drawStr(20,35,"wait:   10 s");
   
  } while( u8g.nextPage() );
  delay(100);   
}
