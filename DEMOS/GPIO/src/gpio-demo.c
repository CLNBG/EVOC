
// 引入BPI头文件

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "bpi_api.h"

// 链接BPI库
// 如果是64bit系统，需要链接BPI41-x64.lib
// 如果是32bit系统，需要链接BPI41-Win32.lib
#if 0
#if defined(_WIN64) || defined(WIN64) || defined(_WIN64_)
#pragma comment(lib, "BPI41-x64.lib")
#else
#pragma comment(lib, "BPI41-Win32.lib")
#endif
#endif


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

	// 设置GPIO1引脚为输出模式
	bpi_set_gpio_mode(BPI_GPIO_1, BPI_GPIO_OUTPUT);

	while (1)
    {
		// GPIO1 拉高
		bpi_set_gpio_output_level(BPI_GPIO_1, BPI_GPIO_HIGH_LEVEL);

		printf("GPIO1 set to High level\n");

		Sleep(1000);

		// GPIO1 拉低
		bpi_set_gpio_output_level(BPI_GPIO_1, BPI_GPIO_LOW_LEVEL);
		printf("GPIO1 set to Low level\n");

		Sleep(1000);
	}


	return 0;
}
