#include "send.h"
#include "gpio.h"
#include "usart.h"
#include "stm32f4xx_hal.h"

uint8_t UART2_txBuffer[4] = "hej4";

void send()
{

	HAL_UART_Transmit(&huart2, UART2_txBuffer, 4, 100);

};
