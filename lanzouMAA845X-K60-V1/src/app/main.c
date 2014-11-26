/******************** (C) COPYRIGHT 2011 ������ӹ����� ********************
 * �ļ���       ��main.c
 * ����         ������ģ��ʵ��
 *
 * ʵ��ƽ̨     ��landzo���ӿ�����
 * ��汾       ��
 * Ƕ��ϵͳ     ��
 *
 * ����         ��Ұ��Ƕ��ʽ����������/landzo ������
 * �Ա���       ��http://landzo.taobao.com/

**********************************************************************************/


#include "include.h"



/*
*********************************************************************************************************
* Description: define
*********************************************************************************************************
*/



//xyz_status xyz;


extern u8 TIME0flag_5ms   ;
extern u8 TIME0flag_10ms  ;
extern u8 TIME0flag_15ms  ;
extern u8 TIME0flag_20ms  ;
extern u8 TIME1flag_1s ;
extern u8 ar1_ad;
extern u8 ar2_ad;


u8 XYZ_CFG_Data ;
u8 y,z,value;

void main()
{
      DisableInterrupts;                             //��ֹ���ж� 
      

   //������Ӵ���
 
      uart_init (UART5 , 115200);                      //��ʼ��UART0�������PTA15�������PTA14������Ƶ�� 9600
      gpio_init (PORTA , 17, GPO,HIGH); 
      pit_init_ms(PIT0, 1);
      pit_init_ms(PIT1, 100);
      //��ʼ��PIT0����ʱʱ��Ϊ�� 5ms
     I2C_init (I2C0) ;   //I2C��ʼ��
     acci2c_set();       //I2C���ٶ����� 
     
     
        FTM_PWM_init(FTM0, CH4, 35000, 0);//right go PTD4
        FTM_PWM_init(FTM0, CH5, 35000, 0);//left  go  PTD5
        FTM_PWM_init(FTM0, CH6, 35000, 50);//right back  PTD6
        FTM_PWM_init(FTM0, CH7, 35000, 50);//left back   PTD7
     
     
     EnableInterrupts;			                    //�����ж�  
    
    /******************************************
    ִ�г���
    ******************************************/
    while(1)
    {
     
         power_get();
       
      
     //  AngularAD_get();
      /*********************
      5ms����ִ�д����
      *********************/
      if(TIME0flag_5ms == 1)
      { 
        TIME0flag_5ms = 0 ;
        acc_ad_get();//���ٶ�ADֵ��ȡ
      //  balance_duty();
      //  carrun();
      }
      
      /*********************
      10ms����ִ�д����
      *********************/
      if(TIME0flag_10ms == 1)
      {
        TIME0flag_10ms = 0 ;

     

 

      }
      
      /*********************
      15ms����ִ�д����
      *********************/
       if(TIME0flag_15ms == 1)
      {
        TIME0flag_15ms = 0 ;
     //    uart_putchar(UART0,0xff);
        
      }
      
      /*********************
      20ms����ִ�д����
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
