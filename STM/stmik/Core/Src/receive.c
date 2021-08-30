#include "receive.h"
#include "gpio.h"
#include "usart.h"
#include "stm32f4xx_hal.h"

uint8_t Rx_data[4];
char * option;

char* receive()
{
HAL_UART_Receive(&huart2, Rx_data, 4, 5000);


option = Rx_data;
if(strcmp(option, "PING") == 0)
{
  HAL_UART_Transmit_IT(&huart2, "PONG", 4);
 // HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
}

	  return option;
};
