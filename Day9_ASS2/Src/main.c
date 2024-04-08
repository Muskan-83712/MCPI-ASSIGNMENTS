/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "lis3dsh.h"
#include "i2c_lcd.h"
#include "led.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	int ret;
	LIS_Data val;
	SystemInit();
	LedInit(LED_GREEN);
	LedInit(LED_ORANGE);
	LedInit(LED_RED);
	LedInit(LED_BLUE);
	LIS_Init();
	DelayMs(50);

	while(1)
	{
		ret = LIS_DRdy();
		if(ret)
		{
			val = LIS_GetData();
			DelayMs(50);


			if(val.x < -2000)
			{
				LedOn(LED_GREEN);
				LedOff(LED_RED);
				LedOff(LED_ORANGE);
				LedOff(LED_BLUE);
			}

			else if(val.x > 2000)
			{
				LedOn(LED_RED);
				LedOff(LED_GREEN);
				LedOff(LED_ORANGE);
				LedOff(LED_BLUE);
			}

			else if(val.y < -2000)
			{
				LedOn(LED_BLUE);
				LedOff(LED_RED);
				LedOff(LED_ORANGE);
				LedOff(LED_GREEN);
			}

			else if(val.y > 2000)
			{
				LedOn(LED_ORANGE);
				LedOff(LED_RED);
				LedOff(LED_GREEN);
				LedOff(LED_BLUE);
			}
		}
	}
		return 0;
}





