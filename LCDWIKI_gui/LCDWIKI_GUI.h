#ifndef _LCDWIKI_GUI_H_
#define _LCDWIKI_GUI_H_

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifdef __AVR__
#include <avr/pgmspace.h>
#elif defined(ESP8266)
 #include <pgmspace.h>
#else
#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#define pgm_read_word(addr) (*(const unsigned short *)(addr))
#endif


//#if !defined(AVR)
//#include <avr/dtostrf.h>
//#endif

#define LEFT 0
#define RIGHT 9999
#define CENTER 9998

class LCDWIKI_GUI
{
	public:
	LCDWIKI_GUI(void); // Constructor

    //These are defined by the subclass:
	virtual uint16_t color565(uint8_t r, uint8_t g, uint8_t b)=0;
	virtual void drawPx(int16_t x, int16_t y, uint16_t color)=0;
	virtual void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)=0;
	virtual void Set_Addr_Window(int16_t x1, int16_t y1, int16_t x2, int16_t y2)=0;
	virtual void Push_Any_Color(uint16_t * block, int16_t n, bool first, uint8_t flags)=0;
	virtual int16_t Read_GRAM(int16_t x, int16_t y, uint16_t *block, int16_t w, int16_t h)=0;
	virtual int16_t Get_Height(void) const=0;
  	virtual int16_t Get_Width(void) const=0;

	//These exist only with LCDWIKI_GUI(no subclass overrides)
	void setColor(uint16_t color);
	void setColor(uint8_t r, uint8_t g, uint8_t b);
	uint16_t getColor(void) const;
	void set(int16_t x, int16_t y);
	uint16_t get(int16_t x, int16_t y);
	void drawVLine(int16_t x, int16_t y, int16_t h);
	void drawHLine(int16_t x, int16_t y, int16_t w);
	void background(uint16_t color);
	void background(uint8_t r, uint8_t g, uint8_t b);
	void drawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2);
	void drawRect(int16_t x1, int16_t y1, int16_t x2, int16_t y2);
	void fillRect(int16_t x1, int16_t y1, int16_t x2, int16_t y2);
	void drawRoundRect(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t radius);
	void fillRoundRect(int16_t x1, int16_t y1, int16_t x2,int16_t y2, int16_t radius);
	void drawCircle(int16_t x, int16_t y, int16_t radius);
	void drawCircleHelper(int16_t x0, int16_t y0, int16_t radius, uint8_t cornername);
	void fillCircle(int16_t x, int16_t y, int16_t radius);
	void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta);
	void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,int16_t x2, int16_t y2);
	void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,int16_t x2, int16_t y2);
	void drawBMP(int16_t x, int16_t y, int16_t sx, int16_t sy, const uint16_t *data, int16_t scale);
 	void setCursorPos(int16_t x, int16_t y);
	int16_t getCursorX(void) const;
	int16_t getCursorY(void) const;
	void setTextColor(uint16_t color);
	void setTextColor(uint8_t r, uint8_t g, uint8_t b);
	uint16_t getTextColor(void) const;
	void setTextBackgroundColor(uint16_t color); 
	void setTextBackgroundColor(uint8_t r, uint8_t g, uint8_t b); 
	uint16_t getTextBackgroundColor(void) const;
	void setTextSize(uint8_t s);
	uint8_t getTextSize(void) const;
	void setTextMode(boolean mode);
	boolean getTextMode(void) const;
	size_t print(uint8_t *st, int16_t x, int16_t y);
	void drawStr(const uint8_t *st, int16_t x, int16_t y);
	void drawStr(uint8_t *st, int16_t x, int16_t y);
	void drawStr(String st, int16_t x, int16_t y);
	void drawInt(long num, int16_t x, int16_t y, int16_t length, uint8_t filler, int16_t system);
	void drawFloat(double num, uint8_t dec, int16_t x, int16_t y, uint8_t divider, int16_t length, uint8_t filler);
    void drawChar(int16_t x, int16_t y, uint8_t c, uint16_t color,uint16_t bg, uint8_t size, boolean mode);
	size_t write(uint8_t c);
	int16_t getWidth(void) const;
	int16_t getHeight(void) const; 
	protected:
	int16_t text_x, text_y;
	uint16_t text_color, text_bgcolor,draw_color;
	uint8_t text_size;
	boolean text_mode; //if set,text_bgcolor is invalid
};

#endif

