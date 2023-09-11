
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

	while(1)
	{
		bpi_turn_on_beep();
		Sleep(1000);
		bpi_turn_off_beep();
		Sleep(1000);
	}

	return 0;
}
