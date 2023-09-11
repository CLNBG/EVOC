
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "bpi_api.h"

int main(int argc, char* argv[])
{
    UINT16 timeout;
	// 初始化BPI
	if (BPI_SUCCESS != bpi_init())
	{
		printf("bpi_init fail\n");
		getchar();
		exit(-1);
	}
	printf("bpi init success\n");

	bpi_start_watchdog(10, BPI_WATCHDOG_SECOND_MODE);
	printf("start watchdog\n");

	Sleep(3000);

	bpi_feed_watchdog(5);
	printf("feed watchdog\n");

	Sleep(3000);

	if(BPI_SUCCESS == bpi_get_watchdog_current_timeout_value(&timeout))
	{
		printf("timeout is %d ", timeout);
	}

	bpi_stop_watchdog();
	printf("stop watchdog\n");
	
	return 0;
}
