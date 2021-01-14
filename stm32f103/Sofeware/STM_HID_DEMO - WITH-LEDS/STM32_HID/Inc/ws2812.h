#ifndef WS2812_STDDRIVER
#define WS2812_STDDRIVER

#include "main.h"
#include "stm32f1xx_hal.h"
#define WS2812_Pin GPIO_PIN6
#define WS2812_GPIO GPIOA
#define WS2812_NUM 6
void WS2812_Init(void);
void WS2812_Color_Set(uint32_t color);
#endif
