#include "power_display.h"
#include "include.h"

/*******电源电压显示程序*********/
u8 ad_power;
float power; 
int prepower_int = 0;
int power_get()
{
    adc_init(ADC1,SE17);
    u8 ad_power = ad_ave10(ADC1,SE17,ADC_8bit,10);
    
    power = 0.0356103515625*ad_power; //  0.0356103515625=（3.3/256）×（15470/5600）   
    
    
    if((int)(power*100)!=prepower_int)
    {
        printf("电源电压为：%f V\n\n",power);
        prepower_int = (int)(power*100);
    }
    return (prepower_int);
}

