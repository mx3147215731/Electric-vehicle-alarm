#include"reg52.h"
#include<intrins.h>

#define ON 1
#define  OFF 0

sbit switcher =P1^0;
sbit  D0_ON=P1^1;
sbit  D1_OFF=P1^2;
sbit vibrate=P1^3; //继电器开关



void Delay2000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 15;
	j = 2;
	k = 235;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void Delay300ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 3;
	j = 26;
	k = 223;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{
	int mark = OFF;
	
 while(1) //查询
 {
   //1. if A 按键被按下 -- 设置为警报模式 -- 长响进入警报模式
	  if(D0_ON==1)
		{
			// 设为警报模式
     mark =ON;
			//响两秒
		 switcher=0;
     Delay2000ms();
     switcher=1;

    }
	 
	 
	
	 
	 //2.if B按键被按下，设为关闭模式  -- 短响解除警报模式
    if(D1_OFF==1)
		{
			// 关闭警报模式
     mark =OFF;
			//响两秒
		 switcher=0;
     Delay300ms();
     switcher=1;

    }
	 
		 //1.1 警报模式下，发生振动 -- 喇叭响
	 //1.2 警报模式下，没有振动 -- 喇叭不响
		if(mark==ON)
		{
     if(vibrate == 0) //发生振动响一会
		 {
      switcher=0;
     Delay300ms();
     switcher=1;
      }
			else  //不发生振动就都不响
				 switcher=1;
    }
} 

}