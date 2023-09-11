
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "bpi_api.h"

int main(int argc, char* argv[])
{
	// 初始化BPI
	if (BPI_SUCCESS != bpi_init())
	{
		printf("bpi_init fail\n");
		getchar();
		exit(-1);
	}

	while(1)
	{
		bpi_led_on(BPI_LED_1);
		bpi_led_on(BPI_LED_2);
		bpi_led_on(BPI_LED_3);
		bpi_led_on(BPI_LED_4);
		bpi_led_on(BPI_LED_5);
		printf("LED 1 on\n");

		Sleep(1000);
		
		bpi_led_off(BPI_LED_1);
		bpi_led_off(BPI_LED_2);
		bpi_led_off(BPI_LED_3);
		bpi_led_off(BPI_LED_4);
		bpi_led_off(BPI_LED_5);
		printf("LED 1 off\n");
		Sleep(1000);
	}

	return 0;
}
