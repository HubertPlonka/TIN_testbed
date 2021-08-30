#include "receive.h"
#include "gpio.h"
#include "usart.h"
#include "stm32f4xx_hal.h"

uint8_t Rx_data[4];
char * option;

char* receive()
{
HAL_UART_Receive (&huart2, Rx_data, 4, 5000);
	  if((Rx_data[0] == 'P') && (Rx_data[1] == 'I') && (Rx_data[2] == 'N') && (Rx_data[3] == 'G'))
	  {
		  HAL_UART_Transmit(&huart2, "PONG", 4, 100);
	  }
	  char* option = (char*) Rx_data;
	  return option;
};
