


#ifndef  calculation_H
#define  calculation_H  


#define   ACC_ZOUT_0     28900  //z轴重力加速度为0时的AD值                                   5
#define   ACC_XOUT_0     29000 //x轴重力加速度为0时的AD值    
#define   ADCOUT  10   //角速度取10次AD值，并求平均值
#define   GYRO_ZERO     35525
#define   GYRO_SCALE	69.16    // 13.3*6/deg.c
float angle_get(void);
void AngleAcceleration_init(void);
float angular_get(void);
//void Kalman_filter(void);


#endif
