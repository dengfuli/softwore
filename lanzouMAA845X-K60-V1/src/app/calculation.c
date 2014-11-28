
#include "common.h"
#include "include.h"
#include "calculation.h"
#include "MOTOR.h"


extern u8 y;
extern u8 z;
extern u8 XYZ_CFG_Data;
/*********************************************************** 
�������ƣ�LCD_KEY_init
�������ܣ�
��ڲ�����
���ڲ������� 
�� ע�� 
***********************************************************/
void LCD_KEY_init (void)
{
    gpio_init (PORTC , 6,  GPO, HIGH) ;
    gpio_init (PORTC , 7,  GPO, HIGH) ;
    gpio_init (PORTC , 8,  GPO, HIGH) ;
    gpio_init (PORTC , 9,  GPO, HIGH) ;
    gpio_init (PORTC , 11, GPO, HIGH) ;
    LCD_init(); 
}
/*********************************************************** 
�������ƣ�LCDTIME
�������ܣ�Һ����ʾ��
��ڲ�����c	:  ��ʾ���ַ�
���ڲ������� 
�� ע�� 
***********************************************************/

void LCDTIME(void)
{
               u8 a,b,c;
              
              
              a=(u8)((power_get()/100)+48);
              b=(u8)(((power_get()%100)/10)+48);
              c=(u8)((power_get()%10)+48);
              
              
          
              
              LCD_set_XY(0,0);
              
              LCD_write_char(a);
              LCD_write_char('.');
              LCD_write_char(b);
              LCD_write_char(c);
              LCD_write_char('V');
}

/*********************************************************** 
�������ƣ�AngleAcceleration_init   
�������ܣ����ٶȽǶȴ�������ʼ������
��ڲ�����
���ڲ������� 
�� ע�� 
***********************************************************/
void AngleAcceleration_init(void)
{
     adc_init(ADC0, AD8) ;     //PTB0
     adc_init(ADC0, AD9) ;     //PTB1
   //  adc_init(ADC0, AD12) ;     //PTB2
    // adc_init(ADC0, AD13) ;     //PTB3
     //adc_init(ADC0, AD14) ;     //PTC0
     //adc_init(ADC0, AD15) ;     //PTC1  
}

/*********���ٶ�AD��ȡ************/

void AngularAD_get(void)
{      
    // u8 ar2_ad = ad_ave10(ADC0, AD8,  ADC_16bit, ADCOUT) ;  //AR2
    // u8 ar1_ad = ad_ave10(ADC0, AD9,  ADC_16bit, ADCOUT) ;  //AR1
     u16 ar1_ad = ad_once(ADC0,AD8, ADC_16bit) ; 
     printf("ar1 = %d",ar1_ad);
}


/*********���ٶ�ADֵ��ȡ**********/
#define   SAVEADRESS   (0X1C)
void acc_ad_get(void)
{
     
      XYZ_CFG_Data = I2C_ReadAddr(I2C0, SAVEADRESS,0x00);
       if(XYZ_CFG_Data&0x80)
      {
        XYZ_CFG_Data = I2C_ReadAddr(I2C0, SAVEADRESS,0x03);
        y = XYZ_CFG_Data;

        XYZ_CFG_Data = I2C_ReadAddr(I2C0, SAVEADRESS,0x05);
        z = XYZ_CFG_Data;
       
        y = y - 96;
        z = z + 96;
      // float angle100 = angle_get()*100;
     //  int angle =(int)(angle100);
      //  printf("y= %d z= %d angle= %d\n\n",y,z,angle);
       
      }
}

float angle_get(void)
{
    u8 y_g = y - ACC_YOUT_0;//(y - ACC_YOUT_0) * 0.153125   :(g/64)
    u8 z_g = z - ACC_ZOUT_0;//(z - ACC_ZOUT_0) * 0.153125
    return(57.296*atan2(y_g,z_g));
}
