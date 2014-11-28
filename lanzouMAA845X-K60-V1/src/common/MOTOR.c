#include "common.h"
#include "MOTOR.h"
#include "include.h"
motor_status motor;
car_status car;

float balance_p = 1.0;
/***电机初始化***/
void motor_init()
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
   
    FTM_PWM_Duty(RIGHT_G_FTM,RIGHT_G_CH,motor.right_duty);//right go PTD5
    FTM_PWM_Duty(RIGHT_B_FTM,RIGHT_B_CH,0);//right back  PTD7
    FTM_PWM_Duty(LEFT_G_FTM,LEFT_G_CH,motor.left_duty);//left  go  PTD4
    FTM_PWM_Duty(LEFT_B_FTM,LEFT_B_CH,0);
}
/*****按键控制小车速度********/
void key_speed(void)
{
    motor.left_duty = key_use()*10;
    motor.right_duty = key_use()*10;
}