#include "common.h"
#include "MOTOR.h"
#include "include.h"
motor_status motor;
car_status car;

#define LEFT_DEAD  0
#define RIGHT_DEAD 0

float balance_p;
float balance_d =1.1;

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
     car.angle_set = 53.5;
     car.angular_set = 0;
     car.angle = angle_get();
     car.angular = angular_get();
     if(car.angle<car.angle_set)
     {
         balance_p = 30;
     }
     else
     {
         balance_p = 30;
     }
     motor.balance_duty =(int16)(balance_p*(car.angle - car.angle_set)+balance_d*(car.angular_set - car.angular));
}

void balance_run(int16 duty)
{
                                                      #ifdef MOTOR_PROTECT
                                                        static int protect_count;
                                                        if(duty >= 1000)
                                                        {
                                                          protect_count ++;
                                                          if(protect_count>100)
                                                          {
                                                            motor.left_duty = 0;
                                                            motor.right_duty = 0;
                                                            DisableInterrupts;
                                                          }
                                                        }
                                                        else
                                                        {
                                                          protect_count = 0;
                                                        }
                                                      #endif

    if(duty>=950)       duty = 950;
    else if(duty<=-950) duty = -950;
    
    if(duty>=0)
    {
        FTM_PWM_Duty(LEFT_B_FTM,LEFT_B_CH,0);
        FTM_PWM_Duty(LEFT_G_FTM,LEFT_G_CH,duty+LEFT_DEAD);
        FTM_PWM_Duty(RIGHT_B_FTM,RIGHT_B_CH,0);
        FTM_PWM_Duty(RIGHT_G_FTM,RIGHT_G_CH,duty+RIGHT_DEAD);
    }
    else
    {
        FTM_PWM_Duty(LEFT_G_FTM,LEFT_G_CH,0);
        FTM_PWM_Duty(LEFT_B_FTM,LEFT_B_CH,-duty+LEFT_DEAD);
        FTM_PWM_Duty(RIGHT_G_FTM,RIGHT_G_CH,0);
        FTM_PWM_Duty(RIGHT_B_FTM,RIGHT_B_CH,-duty+RIGHT_DEAD);
    }
}


void motor_set(void)
{
    
    balance_run(motor.balance_duty);
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
    motor.left_duty = DANG*100;
    motor.right_duty = DANG*100;
}