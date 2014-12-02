


#ifndef  calculation_H
#define  calculation_H  


#define   ACC_ZOUT_0     28900  //z轴重力加速度为0时的AD值                                   5
#define   ACC_XOUT_0     29000 //x轴重力加速度为0时的AD值    
#define ADCOUT  10   //角速度取10次AD值，并求平均值

float angle_get(void);
void AngleAcceleration_init(void);
void AngularAD_get(void);

#endif
