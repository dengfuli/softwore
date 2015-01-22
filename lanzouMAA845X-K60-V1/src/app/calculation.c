
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
{   
     u16 ar1_ad = ad_aveN(ADC0, AD8,  ADC_16bit, ADCOUT) ;  //AR1  
     float angular = (ar1_ad - GYRO_ZERO)/GYRO_SCALE;
  //   printf("ad_angular = %f\n\n",angular);
  
     return (angular);
     
}


/*********加速度所测角度值获取**********/


float angle_get(void)
{
   
    u16 z_g = ad_aveN(ADC0, AD9, ADC_16bit, 10) - ACC_ZOUT_0;
    u16 x_g = ACC_XOUT_0 - ad_aveN(ADC1, AD15, ADC_16bit, 10);
    float ang = 57.296*atan2(x_g,z_g);
  //  printf("  ang = %f\n\n",ang);
    return (ang);
  
}

/**********卡尔曼滤波*************/


#define   Kalman_time   0.005 //定义采样时间5毫秒
//状态变换阵
float A1_1 = 1;
float A1_2 = -1*Kalman_time;
float A2_1 = 0;
float A2_2 = 1;
float B1_1 = Kalman_time;
float B2_1 = 0;
float H1_1 = 1;
float H1_2 = 0;
//系数阵  
float Pest1_1;          //先验估计协方差阵 
float Pest1_2;
float Pest2_1;
float Pest2_2;    
float Psta1_1 = 1;      //后验估计协方差阵
float Psta1_2 = 1;  
float Psta2_1 = 1;  
float Psta2_2 = 1;   
float Q1_1 = 0.00001;   //过程激励噪声协方差，0.00001即可
float Q1_2 = 0;  
float Q2_1 = 0;  
float Q2_2 = 0.00001;   //0.00001即可
float K1_1;             //卡尔曼增益
float K2_1;    
float R = 3;          //观测噪声协方差，主要调此参数
float I1_1 = 1;         //单位阵
float I1_2 = 0;  
float I2_1 = 0;  
float I2_2 = 1;   
//状态阵
float Xest1_1;          //先验状态估计
float Xest2_1;          
float Xsta1_1 = 0;      //后验状态估计
float Xsta2_1 = 0;    
float angle;
float angular;

void Kalman_filter()
{
    
    float th_acc,w_gyro;
    th_acc = angle_get();		//加速度计测量的角度
    w_gyro = angular_get();		//陀螺仪测量的角速度
    
    
    /***********************卡尔曼滤波***********************/
    Xest1_1 = Xsta1_1 + A1_2*Xsta2_1 + B1_1*w_gyro;
    Xest2_1 = Xsta2_1;
    
    Pest1_1 = (Psta1_1 + A1_2*Psta2_1) + (Psta1_2 + A1_2*Psta2_2)*A1_2 + Q1_1;
    Pest1_2 =  Psta1_2 + A1_2*Psta2_2;
    Pest2_1 = Psta2_1 + Psta2_2*A1_2;
    Pest2_2 = Psta2_2 + Q2_2;

    K1_1 = Pest1_1/(Pest1_1 + R);
    K2_1 = Pest2_1/(Pest1_1 + R);

    Xsta1_1 = Xest1_1+K1_1*(th_acc - Xest1_1);        
    Xsta2_1 = Xest2_1+K2_1*(th_acc - Xest1_1);        

    Psta1_1 = (I1_1-K1_1) * Pest1_1;   
    Psta1_2 = (I1_1-K1_1) * Pest1_2;
    Psta2_1 =  -K2_1*Pest1_1 + Pest2_1; 
    Psta2_2 =  -K2_1*Pest1_2+  Pest2_2; 
    /********************************************************/
    
    car.angle = Xsta1_1;		//滤波后的角度值
    car.angular = w_gyro - Xsta2_1;	//滤波后的角速度值
    printf("preangle = %f angle = %f angular = %f\n\n",th_acc,car.angle,car.angular);
}


