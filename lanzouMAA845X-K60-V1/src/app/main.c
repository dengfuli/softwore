/******************** (C) COPYRIGHT 2011 蓝宙电子工作室 ********************
 * 文件名       ：main.c
 * 描述         ：工程模版实验
 *
 * 实验平台     ：landzo电子开发版
 * 库版本       ：
 * 嵌入系统     ：
 *
 * 作者         ：野火嵌入式开发工作室/landzo 蓝电子
 * 淘宝店       ：http://landzo.taobao.com/

**********************************************************************************/


#include "include.h"



/*
*********************************************************************************************************
* Description: define
*********************************************************************************************************
*/

extern u8 TIME0flag_5ms   ;
extern u8 TIME0flag_10ms  ;
extern u8 TIME0flag_15ms  ;
extern u8 TIME0flag_20ms  ;
extern u8 TIME1flag_1s ;

s16 CAR_ANGLE_SET = 1754 ;
s16 CAR_GYRO_SET =  1960 ;




void main()
{
      DisableInterrupts;                             //禁止总中断 
      

    //  LCD_KEY_init();
      AngleAcceleration_init();
      uart_init (UART5 , 115200);                      //初始化UART0，输出脚PTA15，输入脚PTA14，串口频率 9600
      gpio_init (PORTA , 17, GPO,HIGH); 
      pit_init_ms(PIT0, 1);
      pit_init_ms(PIT1, 100);
      //初始化PIT0，定时时间为： 5ms

   //   motor_init();
     
   // FTM_PWM_init(FTM0, CH4, 35000, 0);//left go PTD4
   // FTM_PWM_init(FTM0, CH5, 35000, 0);//right go  PTD5
   // FTM_PWM_init(FTM0, CH6, 35000, 50);//left back  PTD6
   // FTM_PWM_init(FTM0, CH7, 35000, 50);//right back   PTD7
 
     
     EnableInterrupts;			                    //开总中断  
    
    /******************************************
    执行程序
    ******************************************/
    while(1)
    {
      //  angular_get();
      //  angle_get();
        Kalman_filter();
     //   LCDTIME();
     //   balance_duty();
     //   motor_set();
           
      //  DELAY_MS(2); 
         
       //  key_speed();
        // carrun();
      /*********************
      5ms程序执行代码段
      *********************/
      if(TIME0flag_5ms == 1)
      { 
      TIME0flag_5ms = 0 ;
      //  carrun();
      }
      
      /*********************
      10ms程序执行代码段
      *********************/
      if(TIME0flag_10ms == 1)
      {
        TIME0flag_10ms = 0 ;

     

 

      }
      
      /*********************
      15ms程序执行代码段
      *********************/
       if(TIME0flag_15ms == 1)
      {
        TIME0flag_15ms = 0 ;
     //    uart_putchar(UART0,0xff);
        
      }
      
      /*********************
      20ms程序执行代码段
      *********************/
      if(TIME0flag_20ms == 1)
      {
        TIME0flag_20ms = 0 ;
     //   uart_putchar(UART0,0xff);
        
      }
      
      
      if(TIME1flag_1s == 1)
      {
       PTA17_OUT = ~PTA17_OUT ; 
        TIME1flag_1s = 0 ; 
        
     
      }

    }
}
