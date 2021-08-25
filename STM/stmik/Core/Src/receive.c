#include "receive.h"
#include "gpio.h"
#include "usart.h"
#include "stm32f4xx_hal.h"

uint8_t UART2_rxBuffer[12] = {0};

void receive()
{
	HAL_UART_Receive (&huart2, UART2_rxBuffer, 12, 5000);
//HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
//		HAL_Delay(100);
};
