#ifndef _MOTOR_H
#define _MOTOR_H_

#include"common.h"

/**********电机配置**********/
/***朝车底盘往前看*****/

/***右电机前进FTM模块配置***/
#define RIGHT_G_FTM  FTM0
#define RIGHT_G_CH   CH5  //PTD5

/***右电机后退FTM模块配置***/
#define RIGHT_B_FTM  FTM0
#define RIGHT_B_CH   CH7  //PTD7

/***左电机前进FTM模块配置***/
#define LEFT_G_FTM  FTM0
#define LEFT_G_CH   CH4   //PTD4

/***左电机后退FTM模块配置***/
#define LEFT_B_FTM  FTM0
#define LEFT_B_CH   CH6   //PTD6

/***电机驱动频率***/
#define MOTOR_FREQ 10000

/***电机驱动初始化占空比***/
#define INIT_DUTY 0

extern float blance_p;
extern float blance_d;


typedef struct car_status
{
    float angle_set;
    float angular_set;
    float speed_set;
    float angle; 
    float angular;
}car_status;


typedef struct motor_status
{
    int8 balance_duty;
    int8 left_duty;
    int8 right_duty;

}motor_status;

void key_speed(void);
void balance_duty(void);
void carrun(void);
#endif
