
#include "common.h"
#include "include.h"
#include "calculation.h"
#include "MOTOR.h"





/*********************************************************** 
函数名称：AngleAcceleration_init   
函数功能：加速度角度传感器初始化程序
入口参数：
出口参数：无 
备 注： 
***********************************************************/
void AngleAcceleration_init(void)
{
     adc_init(ADC0, AD8) ;     //PTB0   AR1
     adc_init(ADC0, AD9) ;     //PTB1 z
     adc_init(ADC1, AD15) ;     //PTB11  x
   //  adc_init(ADC0, AD13) ;     //PTB3
   //  adc_init(ADC1, AD10) ;     //PTB4   AR2
     //adc_init(ADC0, AD15) ;     //PTC1  
}

/*********角速度AD获取,返回角度************/

float angular_get(void)
{   //  int i,sum=0;
   //  u16 ar2_ad = ad_aveN(ADC1, AD10,  ADC_16bit, ADCOUT) ;  //AR2
     u16 ar1_ad = ad_aveN(ADC0, AD8,  ADC_16bit, ADCOUT) ;  //AR1
  //   printf("ar1 = %d  ar2 = %d\n\n",ar1_ad,ar2_ad);
     float angular = (ar1_ad - GYRO_ZERO)/GYRO_SCALE;
  //   for(i=0;i<10000;i++)
  //   {
  //       sum = sum+ar1_ad;
  //   }
     //  printf("%f\n\n",angular);
     
     return(angular);
     
}


/*********加速度所测角度值获取**********/


float angle_get(void)
{
    u16 z_g =ad_aveN(ADC0, AD9, ADC_16bit, 10) - ACC_ZOUT_0  ;
    u16 x_g = ad_aveN(ADC1, AD15, ADC_16bit, 10) - ACC_XOUT_0;
    float ang = 57.296*atan2(x_g,z_g);
   // printf("%d %d\n\n",x_g,z_g);
    return (57.296*atan2(x_g,z_g));
   
}




