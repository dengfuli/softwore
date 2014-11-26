/******************** (C) COPYRIGHT 2011 ������ӹ����� ********************
 * �ļ���       ��AT24C02.h
 * ����         ��AT24C02оƬ������������
 *
 * ʵ��ƽ̨     ��
 * ��汾       ��
 * Ƕ��ϵͳ     ��
 *
 * ����         ��
 * �Ա���       ��http://landzo.taobao.com/
 * ����֧����̳ ��
**********************************************************************************/



#ifndef _AT24C02_H_
#define _AT24C02_H_

#define AT24C02_I2C_ADDRESS                         0x50
#define AT24C02_PageSize                            8			/* AT24C02ÿҳ��8���ֽ� */


#define AT24C02_init()                              I2C_init(I2C0)

#define AT24C02_WriteByte(Addr,Data)                I2C_WriteAddr(I2C0,AT24C02_I2C_ADDRESS,Addr,Data)   //��ȡ��ַ�������
#define AT24C02_ReadByte(Addr)                      I2C_ReadAddr(I2C0,AT24C02_I2C_ADDRESS,Addr)          //�ӵ�ַ��ȡ����

#endif  //_AT24C02_H_