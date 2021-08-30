#include "send.h"
#include "gpio.h"
#include "usart.h"
#include "stm32f4xx_hal.h"

uint8_t UART2_txBuffer[22] = {0};

void send(char * reading)
{

	HAL_UART_Transmit(&huart2, reading, 22, 100);

};
