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
LCD_init          : 5110LCD��ʼ��

��д����          ��2012-11-01
����޸�����      ��2012-11-01
-----------------------------------------------------------------------*/
#define LCD_RST   PTC15_OUT 
#define LCD_CE    PTC6_OUT
#define SDIN      PTB22_OUT
#define SCLK      PTB21_OUT
#define LCD_DC    PTC7_OUT


void delay_1us(void)  ;
void delay_1ns(void)  ;
void LCD_clear(void);
void LCD_write_byte(u8 dat, u8 command);
void LCD_init(void) ;
void LCD_write_char(u8 c) ;
void LCD_set_XY(u8 X, u8 Y);



    

/********************************************************************/

#endif
