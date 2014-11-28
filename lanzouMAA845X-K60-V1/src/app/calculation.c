
#include "common.h"
#include "include.h"
#include "calculation.h"
#include "MOTOR.h"


/*********************************************************** 
函数名称：LCD_KEY_init
函数功能：
入口参数：
出口参数：无 
备 注： 
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
函数名称：LCDTIME
函数功能：液晶显示和
入口参数：c	:  显示的字符
出口参数：无 
备 注： 
***********************************************************/

void LCDTIME(void)
{
      /*  
        LCD_write_chinese_string(0,0,12,7,0,0);//电
	LCD_write_chinese_string(12,0,12,7,1,0);//源
	LCD_write_chinese_string(24,0,12,7,2,0);//电
        LCD_write_chinese_string(36,0,12,7,3,0);//压
       */
        power_display();
        angle_display();
}

/*********************************************************** 
函数名称：AngleAcceleration_init   
函数功能：加速度角度传感器初始化程序
入口参数：
出口参数：无 
备 注： 
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

/*********角速度AD获取************/

void AngularAD_get(void)
{      
    // u8 ar2_ad = ad_ave10(ADC0, AD8,  ADC_16bit, ADCOUT) ;  //AR2
    // u8 ar1_ad = ad_ave10(ADC0, AD9,  ADC_16bit, ADCOUT) ;  //AR1
     u16 ar1_ad = ad_once(ADC0,AD8, ADC_16bit) ; 
     printf("ar1 = %d",ar1_ad);
}


/*********加速度AD值获取**********/


u8 XYZ_CFG_Data ;
u8 y,z,value;
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

int angle_get(void)
{
    u8 y_g = y - ACC_YOUT_0;//(y - ACC_YOUT_0) * 0.153125   :(g/64)
    u8 z_g = z - ACC_ZOUT_0;//(z - ACC_ZOUT_0) * 0.153125
    int angle100 = (int)((57.296*atan2(y_g,z_g))*10);
    return (angle100);//返回角度的10倍
}
