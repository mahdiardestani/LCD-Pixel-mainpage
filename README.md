# LCD-Pixel
For coding on oled lcd you should include Uglib.h in your arduino ide.you can go to sketch and then in manage library install it.
oled lcd have 7 pins which that 2 pins of 7 pins are vcc and gnd ond other pins should connected to digitalpins on arduino board.
for initiate lcd use of this command U8GLIB_SSD1306_128X64 u8g(D0,D1,CS,DC,RESET).
     D0=sck=Pin->5
     D1=mosi=Pin->6
     CS=Pin->3
     DC=A0=Pin->8
     Reset=Pin->7
