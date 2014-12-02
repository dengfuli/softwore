
#include "common.h"
#include "include.h"
#include "calculation.h"
#include "MOTOR.h"






/*********************************************************** 
�������ƣ�AngleAcceleration_init   
�������ܣ����ٶȽǶȴ�������ʼ������
��ڲ�����
���ڲ������� 
�� ע�� 
***********************************************************/
void AngleAcceleration_init(void)
{
     //adc_init(ADC0, AD8) ;     //PTB0
   //  adc_init(ADC0, AD9) ;     //PTB1
     adc_init(ADC0, AD12) ;     //PTB2
   //  adc_init(ADC0, AD13) ;     //PTB3
     adc_init(ADC0, AD14) ;     //PTC0
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


/*********���ٶ�����Ƕ�ֵ��ȡ**********/


float angle_get(void)
{
    u16 z_g =ad_aveN(ADC0, AD14, ADC_16bit, 10) - ACC_ZOUT_0  ;
    u16 x_g = ad_aveN(ADC0, AD12, ADC_16bit, 10) - ACC_XOUT_0;
    float ang = 57.296*atan2(x_g,z_g);
  //  printf("%d %d\n\n",x_g,z_g);
   // printf("%d\n\n",(int)(ang));
    return (57.296*atan2(x_g,z_g));
   
}
