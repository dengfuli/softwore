


#ifndef  calculation_H
#define  calculation_H  

#define   ACC_YOUT_0     163  //y���������ٶ�Ϊ0ʱ��ADֵ
#define   ACC_ZOUT_0     93   //z���������ٶ�Ϊ0ʱ��ADֵ                                   5

#define ADCOUT  10   //���ٶ�ȡ10��ADֵ������ƽ��ֵ

int angle_get(void);
void acc_ad_get(void);
void LCD_KEY_init (void);
void AngularAD_get(void);
void LCDTIME(void);
#endif
