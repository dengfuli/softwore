#include "power.h"
#include "include.h"

/*******��Դ��ѹ��ʾ����,���򷵻ص�Դ��ѹ��100ֵ*********/
u8 ad_power;
float power; 
int prepower_int = 0;
int power_get()
{
    adc_init(ADC1,SE17);
    u8 ad_power = ad_ave10(ADC1,SE17,ADC_8bit,10);
    
    power = 0.0356103515625*ad_power; //  0.0356103515625=��3.3/256������15470/5600��   
    
    
    if((int)(power*100)!=prepower_int)
    {
        printf("��Դ��ѹΪ��%f V\n\n",power);
        prepower_int = (int)(power*100);
    }
    return (prepower_int);//���ص�Դ��ѹ��100ֵ
}

/***********��ʾ��Դ��ѹ*************/
void power_display(void)
{
    
              u8 a,b,c;
              a=(u8)((power_get()/100)+48);
              b=(u8)(((power_get()%100)/10)+48);
              c=(u8)((power_get()%10)+48);
              LCD_set_XY(0,0);
              LCD_write_char('P');
              LCD_write_char('O');
              LCD_write_char('W');
              LCD_write_char('E');
              LCD_write_char('R');
              LCD_write_char(':');
              LCD_write_char(a);
              LCD_write_char('.');
              LCD_write_char(b);
              LCD_write_char(c);
              LCD_write_char('V');
  
}
