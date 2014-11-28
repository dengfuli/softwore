


#ifndef  calculation_H
#define  calculation_H  

#define   ACC_YOUT_0     163  //y轴重力加速度为0时的AD值
#define   ACC_ZOUT_0     93   //z轴重力加速度为0时的AD值                                   5

#define ADCOUT  10   //角速度取10次AD值，并求平均值

int angle_get(void);
void acc_ad_get(void);
void LCD_KEY_init (void);
void AngularAD_get(void);
void LCDTIME(void);
#endif
