#include "U8glib.h"

//**************************************************
U8GLIB_SSD1306_128X64 u8g(5, 6, 9, 8, 7);
//**************************************************

int step =40;
void setup()
{
  /* nothing to do here */
  u8g.setFont(u8g_font_unifont);
}

void loop()
{
  u8g.firstPage();
  do
  {
    int y = 60;
    u8g.setColorIndex(1);                   //one set color white  
    u8g.drawFilledEllipse(65,10,20,10,U8G_DRAW_UPPER_RIGHT);
    u8g.drawFilledEllipse(65,10,20,10,U8G_DRAW_UPPER_LEFT);
    u8g.setColorIndex(0);                   //zero set color black
    u8g.drawFilledEllipse(65,10,15,5,U8G_DRAW_UPPER_RIGHT);
    u8g.drawFilledEllipse(65,10,15,5,U8G_DRAW_UPPER_LEFT);
    u8g.setColorIndex(1);
    u8g.drawBox(45, 15, 41, 5);
    u8g.drawBox(63,20,5,15);
    u8g.drawBox(73,25,5,10);
    u8g.drawFilledEllipse(70,35,7,7,U8G_DRAW_LOWER_RIGHT);
    u8g.drawFilledEllipse(70,35,7,7,U8G_DRAW_LOWER_LEFT);
    u8g.setColorIndex(0);
    u8g.drawFilledEllipse(70,35,2,2,U8G_DRAW_LOWER_RIGHT);
    u8g.drawFilledEllipse(70,35,2,2,U8G_DRAW_LOWER_LEFT);
    u8g.setColorIndex(1);
    u8g.drawLine(40, y, step, y);
    step ++;
    if(step >= 90){
      step = 40;
    }
    
    delay(100);
  } while (u8g.nextPage());
}
