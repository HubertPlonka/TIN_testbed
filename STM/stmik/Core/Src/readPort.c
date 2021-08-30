#include "readPort.h"
#include "gpio.h"
#include "usart.h"
#include "stm32f4xx_hal.h"

char * reading;

char * readPort(char * port)
{
	if (port == "RDPB") {
		reading[0] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
		reading[1] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2);
		reading[2] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10);
		reading[3] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
		reading[4] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
		reading[5] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
	}
	else if(port == "RDPC") {
		reading[0] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10);
		reading[1] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);
		reading[2] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9);
		reading[3] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7);
		reading[4] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);
		reading[5] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);
		reading[6] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);
		reading[7] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);
	}
	else if (port == "RDPD") {
		reading[0] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2);
		reading[1] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3);
		reading[2] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0);
		reading[3] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1);
		reading[4] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
		reading[5] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
		reading[6] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
		reading[7] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	}
	else if (port == "RDAL") {
		reading[0] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
		reading[1] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2);
		reading[2] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10);
		reading[3] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
		reading[4] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
		reading[5] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
		reading[6] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10);
		reading[7] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);
		reading[8] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9);
		reading[9] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7);
		reading[10] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);
		reading[11] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);
		reading[12] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);
		reading[13] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);
		reading[14] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2);
		reading[15] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3);
		reading[16] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0);
		reading[17] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1);
		reading[18] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
		reading[19] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
		reading[20] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
		reading[21] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	}
	return reading;
};
