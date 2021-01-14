#include"WS2812.h"
#include "main.h"
#include "stm32f1xx_hal.h"
void WS2812_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = GPIO_PIN_6;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
void WS2812_Write_Byte(uint8_t color)
{
	uint8_t i;
	for(i=0;i<8;i++)
	{
			if((color&0x80)==0x80)
			{
				WS2812_GPIO->BSRR=0X0040;
				__nop();__nop();__nop();__nop();
				__nop();__nop();__nop();__nop();		
				__nop();__nop();__nop();__nop();
				__nop();__nop();__nop();__nop();	
				__nop();__nop();__nop();__nop();
				__nop();__nop();__nop();__nop();
				__nop();__nop();__nop();__nop();				
				__nop();__nop();__nop();__nop();
				__nop();__nop();__nop();__nop();	
				__nop();__nop();__nop();__nop();	
				__nop();__nop();__nop();__nop();				
				WS2812_GPIO->BRR=0X0040;
				__nop();__nop();__nop();__nop();
				__nop();__nop();__nop();__nop();		
				__nop();__nop();__nop();__nop();
			}
			else
			{
				WS2812_GPIO->BSRR=0X0040;
				__nop();__nop();__nop();__nop();
				__nop();__nop();__nop();__nop();
				__nop();__nop();__nop();__nop();
				WS2812_GPIO->BRR=0X0040;
				__nop();__nop();__nop();__nop();
				__nop();__nop();__nop();__nop();		
				__nop();__nop();__nop();__nop();
				__nop();__nop();__nop();__nop();	
				__nop();__nop();__nop();__nop();
				__nop();__nop();__nop();__nop();
				__nop();__nop();__nop();__nop();				
				__nop();__nop();__nop();__nop();	
			}
			color<<=1;
		
}
}
void WS2812_SET_ONE(uint32_t color)
{
	WS2812_Write_Byte((color&0xff0000)>>16);
	WS2812_Write_Byte((color&0x00ff00)>>8);
	WS2812_Write_Byte(color&0xff);
}
void WS2812_Color_Set(uint32_t color)
{
	uint16_t num;
	for(num=0;num<WS2812_NUM;num++)
	{
		WS2812_SET_ONE(color);
	}
	HAL_Delay(80);
}
