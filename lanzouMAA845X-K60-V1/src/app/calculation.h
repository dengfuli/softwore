


#ifndef  calculation_H
#define  calculation_H  


#define   ACC_ZOUT_0     28900  //z���������ٶ�Ϊ0ʱ��ADֵ                                   5
#define   ACC_XOUT_0     29000 //x���������ٶ�Ϊ0ʱ��ADֵ    
#define   ADCOUT  10   //���ٶ�ȡ10��ADֵ������ƽ��ֵ
#define   GYRO_ZERO     35525
#define   GYRO_SCALE	69.16    // 13.3*6/deg.c
float angle_get(void);
void AngleAcceleration_init(void);
float angular_get(void);
//void Kalman_filter(void);


#endif
