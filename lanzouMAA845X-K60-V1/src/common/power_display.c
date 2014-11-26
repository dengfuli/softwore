#include "power_display.h"
#include "include.h"

/*******��Դ��ѹ��ʾ����*********/

float power; 
int prepower_int = 0;
void power_get(void)
{
    adc_init(ADC1,SE17);
    int8 ad_power = ad_ave10(ADC1,SE17,ADC_8bit,10);
    
    power = 0.0356103515625*ad_power; //  0.0356103515625=��3.3/256������15470/5600��   
    
    
    if((int)(power*100)!=prepower_int)
    {
        printf("��Դ��ѹΪ��%f V\n\n",power);
        prepower_int = (int)(power*100);
    }
    
}

