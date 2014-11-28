#include "common.h"
#include "MOTOR.h"
#include "include.h"
motor_status motor;
car_status car;

float balance_p = 1.0;
/***电机初始化***/
void motor_init(void)
{
    FTM_PWM_init(RIGHT_G_FTM,RIGHT_G_CH,MOTOR_FREQ,INIT_DUTY);//right go PTD4
    FTM_PWM_init(RIGHT_B_FTM,RIGHT_B_CH,MOTOR_FREQ,INIT_DUTY);//right back  PTD6
    FTM_PWM_init(LEFT_G_FTM,LEFT_G_CH,MOTOR_FREQ,INIT_DUTY);//left  go  PTD5
    FTM_PWM_init(LEFT_B_FTM,LEFT_B_CH,MOTOR_FREQ,INIT_DUTY);//left back   PTD7
}
/***平衡控制***/

void balance_duty(void)
{
     motor.balance_duty = (int8)(balance_p*(car.angle - car.angle_set));
     motor.left_duty = motor.left_duty + motor.balance_duty;
     motor.right_duty = motor.right_duty + motor.balance_duty;
    
}
/*********小车行驶占空比************/
void carrun(void)
{
   
    FTM_PWM_Duty(RIGHT_G_FTM,RIGHT_G_CH,0);//right go PTD5
    FTM_PWM_Duty(RIGHT_B_FTM,RIGHT_B_CH,motor.right_duty);//right back  PTD7
    FTM_PWM_Duty(LEFT_G_FTM,LEFT_G_CH,0);//left  go  PTD4
    FTM_PWM_Duty(LEFT_B_FTM,LEFT_B_CH,motor.left_duty);
}
/*****按键控制小车速度********/
int DANG = 0;
void key_speed(void)
{
  
     if(!K1_IN)
   {
       
       while(!K1_IN);
      
       if(DANG < 10)
       {
            DANG++;
       }
   }
   if(!K2_IN)
   {
       while(!K2_IN);
       if(DANG > 0)
       {
            DANG--;
       }
   }
   LCD_set_XY(77,0);
   u8 tem = (u8)(DANG+48);
   LCD_write_char(tem);    
    motor.left_duty = DANG*10;
    motor.right_duty = DANG*10;
}