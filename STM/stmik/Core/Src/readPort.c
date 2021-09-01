#include "readPort.h"
#include "gpio.h"
#include "usart.h"
#include "stm32f4xx_hal.h"
#include <string.h>


char * reading;

char * readPort(char * option)
{
	//if (reading[0] == 0) {
						//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
					//} else {
					//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
					//}
	if (strcmp(option, "RDPB") == 0) {

			reading[0] = (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) ? 1 : 0);
			reading[1] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
			reading[2] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
			reading[3] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
			reading[4] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10);
			reading[5] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);
			HAL_UART_Transmit(&huart2, (char *) reading, 6, 100);
		}
		else if(strcmp(option, "RDPC") == 0) {
			reading[0] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);
			reading[1] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);
			reading[2] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);
			reading[3] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9);
			reading[4] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9);
			reading[5] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
		}
		else if (strcmp(option, "RDPD") == 0) {
			reading[0] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_11);
			reading[1] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);
			reading[2] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8);
			reading[3] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5);
			reading[4] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);
			reading[5] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2);
			reading[6] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
			reading[7] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4);
		}
		else if (strcmp(option, "RDPE") == 0) {
			reading[0] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0);
			reading[1] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1);
			reading[2] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
			reading[3] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
		}
	else if (strcmp(option, "RDAL") == 0) {
		reading[0] = (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) ? 1 : 0);
		reading[1] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
		reading[2] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
		reading[3] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
		reading[4] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10);
		reading[5] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);
		reading[6] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);
		reading[7] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);
		reading[8] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);
		reading[9] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9);
		reading[10] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9);
		reading[11] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
		reading[12] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_11);
		reading[13] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);
		reading[14] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8);
		reading[15] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5);
		reading[16] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);
		reading[17] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2);
		reading[18] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
		reading[19] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4);
		reading[20] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0);
		reading[21] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1);
		reading[22] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
		reading[23] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
	}
	return reading;
};
