/*
 * File:		nokia.h
 * Purpose:		Serial Input/Output routines
 *
 */

#ifndef _NOKIA_H
#define _NOKIA_H

#include "gpio.h"
/********************************************************************/
/*-----------------------------------------------------------------------
LCD_init          : 5110LCD初始化

编写日期          ：2012-11-01
最后修改日期      ：2012-11-01
-----------------------------------------------------------------------*/
#define LCD_RST   PTC11_OUT 
#define LCD_CE    PTC8_OUT
#define SDIN      PTC6_OUT
#define SCLK      PTC7_OUT
#define LCD_DC    PTC9_OUT


void delay_1us(void)  ;
void delay_1ns(void)  ;
void LCD_clear(void);
void LCD_write_byte(u8 dat, u8 command);
void LCD_init(void) ;
void LCD_write_char(u8 c) ;
void LCD_set_XY(u8 X, u8 Y);
void LCD_write_english_string(u8 X, u8 Y, u8 *s);
void LCD_write_chinese_string(u8 X, u8 Y, u8 ch_with,u8 num, u8 line, u8 row);
void LCD_draw_bmp_pixel(u8 X,u8 Y,u8 *map,u8 Pix_x,u8 Pix_y);




    

/********************************************************************/

#endif
