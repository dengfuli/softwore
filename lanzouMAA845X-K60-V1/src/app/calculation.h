


#ifndef  calculation_H
#define  calculation_H  


#define   ACC_ZOUT_0     28900  //z���������ٶ�Ϊ0ʱ��ADֵ                                   5
#define   ACC_XOUT_0     29000 //x���������ٶ�Ϊ0ʱ��ADֵ    
#define ADCOUT  10   //���ٶ�ȡ10��ADֵ������ƽ��ֵ

float angle_get(void);
void AngleAcceleration_init(void);
void AngularAD_get(void);

#endif
