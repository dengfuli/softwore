/******************** (C) COPYRIGHT 2011 ������ӹ�����********************
 * �ļ���       ��common.h
 * ����         ��ͨ������ͷ�ļ����ʺ�ȫ���Ĺ���
 *
 * ʵ��ƽ̨     ��
 * ��汾       ��
 * Ƕ��ϵͳ     ��
 *
 * ����         ��
 * �Ա���       ��http://landzo.taobao.com/
 * ����֧����̳ ��
**********************************************************************************/

#ifndef _COMMON_H_
#define _COMMON_H_

//Ϊʹ�÷���ģʽ����ӵģ�����ģʽӦ�����δ��ڷ��͡���PLL���໷����
//#define   Simulator
#ifdef    Simulator
#define NO_PLL_INIT   //�������໷
#define NPRINTF       //����printf
#endif

/********************************************************************/

/*
 * Debug prints ON (#define) or OFF (#undef)
 */
#define DEBUG_PRINT


/*****************************������������*****************************/
typedef 	unsigned 	char		u8;	  //�޷�����
typedef 	unsigned 	short int	u16;
typedef 	unsigned 	long  int	u32;
typedef    	__UINT64_T_TYPE__       u64;

typedef 	char					s8;	  //�з�����
typedef 	short int				s16;
typedef 	long  int				s32;
typedef    	__INT64_T_TYPE__     	s64;

typedef	union
{
	u32	DW;
	u16	W[2];
	u8	B[4];
	struct
	{
		u32 b0:1; u32 b1:1; u32 b2:1; u32 b3:1; u32 b4:1; u32 b5:1; u32 b6:1; u32 b7:1; 
		u32 b8:1; u32 b9:1; u32 b10:1;u32 b11:1;u32 b12:1;u32 b13:1;u32 b14:1;u32 b15:1;
		u32 b16:1;u32 b17:1;u32 b18:1;u32 b19:1;u32 b20:1;u32 b21:1;u32 b22:1;u32 b23:1;
		u32 b24:1;u32 b25:1;u32 b26:1;u32 b27:1;u32 b28:1;u32 b29:1;u32 b30:1;u32 b31:1;
	};
}Dtype;		//sizeof(Dtype)	Ϊ 4 

/*
 * �������е�RAM�ĺ���
 */
#if defined(__ICCARM__)
	#define 	__RAMFUN	__ramfunc	//IAR �� __ramfunc ������
#else
	#define 	__RAMFUN
#endif

/*
 * Include the generic CPU header file
 */
#define ARM_MATH_CM4
#include "arm_math.h"
#include "arm_cm4.h"

/*
 * Include the cpu specific header file
 */
#include "MK60DZ10.h"


/*
 * Include the platform specific header file
 */
#include "k60_fire.h"




/*
 * Include any toolchain specfic header files
 */
#if (defined(CW))
#include "cw.h"
#elif (defined(IAR))
#include "iar.h"
#else
#warning "No toolchain specific header included"
#endif

/*
 * Include common utilities
 */
#include "assert.h"
#include "io.h"
#include "startup.h"
#include "stdlib.h"


#if (defined(IAR))
#include "intrinsics.h"
#endif


#include  "sysinit.h"           //ϵͳ����
#include "mcg.h"
#include "fire_drivers_cfg.h"   //�ܽŸ�������



#include "lptmr.h"
#define DELAY()         time_delay_ms(500)
#define DELAY_MS(ms)    time_delay_ms(ms)



/********************************************************************/

#endif /* _COMMON_H_ */
