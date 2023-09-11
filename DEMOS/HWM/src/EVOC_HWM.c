
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

	printf("bpi init success\n");

	UINT8 temp = 0;

	bpi_get_hhm_temperature(BPI_CPU1_TEMP, &temp);
	printf("CPU temperature: %d\n", temp);

	UINT16 fan = 0;
	bpi_get_hhm_temperature(BPI_CPU1_FAN, &fan);
	printf("FAN Speed: %d\n", temp);

	
	float vol = 0;
	bpi_get_hhm_temperature(BPI_VCC_BAT, &vol);
	printf("BAT voltage: %3.3f\n", vol);

	getchar();

	return 0;
}
