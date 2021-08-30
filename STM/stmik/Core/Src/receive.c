#include "receive.h"
#include "gpio.h"
#include "usart.h"
#include "stm32f4xx_hal.h"

uint8_t Rx_data[4];


void receive(){
HAL_UART_Receive (&huart2, Rx_data, 4, 5000);
	  if((Rx_data[0] == 'p') && (Rx_data[1] == 'i') && (Rx_data[2] == 'n') && (Rx_data[3] == 'g'))
	  {
		  HAL_UART_Transmit(&huart2, "pong", 4, 100);
	  }
};
