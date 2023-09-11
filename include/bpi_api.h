/*
 * BPI interface
 *
 * Copyright (C) EVOC  Corporation, 2022
 * 
 * Author: mgl <sz.glmo@inside.evoc.cn>
 *   Date: 2022-07-20 
 */

#ifndef _BPI_API_H_
#define _BPI_API_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(WIN64) || defined(_WIN64_)
#define PLATFORM_WIN32
#elif defined(linux) || defined(__linux) || defined(__linux__)
#define PLATFORM_LINUX
#endif

#if defined(PLATFORM_WIN32)
#ifdef __cplusplus
#define BPI_API extern "C" __declspec(dllexport)
#else
#define BPI_API __declspec(dllexport)
#endif

#elif defined(PLATFORM_LINUX)
#ifdef __cplusplus
#define BPI_API extern "C"
#else
#define BPI_API
#endif
#endif

typedef unsigned long long UINT64;
typedef unsigned int UINT32;
typedef unsigned short UINT16;
typedef unsigned char UINT8;

#ifndef BPI_FAILURE
#define BPI_FAILURE 0
#endif

#ifndef BPI_SUCCESS
#define BPI_SUCCESS 1
#endif

#ifndef BPI_GPIO_OUTPUT
#define BPI_GPIO_OUTPUT 0
#endif

#ifndef BPI_GPIO_INPUT
#define BPI_GPIO_INPUT 1
#endif

#ifndef BPI_GPIO_HIGH_LEVEL
#define BPI_GPIO_HIGH_LEVEL 1
#endif

#ifndef BPI_GPIO_LOW_LEVEL
#define BPI_GPIO_LOW_LEVEL 0
#endif

#ifndef BPI_WATCHDOG_SECOND_MODE
#define BPI_WATCHDOG_SECOND_MODE 0
#endif

#ifndef BPI_WATCHDOG_MINUTE_MODE
#define BPI_WATCHDOG_MINUTE_MODE 1
#endif

/**********************************************************************************
CPU and system temperature type define
***********************************************************************************/
#define BPI_CPU1_TEMP 0 // CPU1
#define BPI_CPU2_TEMP 1 // CPU2
#define BPI_SYS_TEMP 2	// SYSTEM

/**********************************************************************************
CPU and system fan type define
***********************************************************************************/
#define BPI_CPU1_FAN 0
#define BPI_CPU2_FAN 1
#define BPI_SYS1_FAN 2
#define BPI_SYS2_FAN 3
#define BPI_SYS3_FAN 4

/**********************************************************************************
System voltage type define
***********************************************************************************/
#define BPI_VCC_12 0
#define BPI_VCC_5 1
#define BPI_VCC_CORE 2
#define BPI_VCC_1_2_DDQ 3
#define BPI_VCC_3_3 4
#define BPI_VCC_BAT	5

/**********************************************************************************
System led type define
***********************************************************************************/
#define BPI_LED_1 0
#define BPI_LED_2 1
#define BPI_LED_3 2
#define BPI_LED_4 3
#define BPI_LED_5 4

/**********************************************************************************
GPIO1-GPIO8
***********************************************************************************/
#define BPI_GPIO_1 1
#define BPI_GPIO_2 2
#define BPI_GPIO_3 3
#define BPI_GPIO_4 4
#define BPI_GPIO_5 5
#define BPI_GPIO_6 6
#define BPI_GPIO_7 7
#define BPI_GPIO_8 8

/**********************************************************************************
GPIO9-GPIO16
***********************************************************************************/
#define BPI_GPIO_9 9
#define BPI_GPIO_10 10
#define BPI_GPIO_11 11
#define BPI_GPIO_12 12
#define BPI_GPIO_13 13
#define BPI_GPIO_14 14
#define BPI_GPIO_15 15
#define BPI_GPIO_16 16

/**********************************************************************************
GPIO17-GPIO24
***********************************************************************************/
#define BPI_GPIO_17 17
#define BPI_GPIO_18 18
#define BPI_GPIO_19 19
#define BPI_GPIO_20 20
#define BPI_GPIO_21 21
#define BPI_GPIO_22 22
#define BPI_GPIO_23 23
#define BPI_GPIO_24 24

/**********************************************************************************
GPIO25-GPIO32
***********************************************************************************/
#define BPI_GPIO_25 25
#define BPI_GPIO_26 26
#define BPI_GPIO_27 27
#define BPI_GPIO_28 28
#define BPI_GPIO_29 29
#define BPI_GPIO_30 30
#define BPI_GPIO_31 31
#define BPI_GPIO_32 32

/**********************************************************************************
Function	: 	bpi_init
Description : 	This function initialization bpi, which must be called before using bpi api
Input		: 	NONE
Output		: 	NONE
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example		:
				if (BPI_FAILURE == bpi_init()) {
					exit(-1);
				}

				// call bpi api

***********************************************************************************/
BPI_API int bpi_init(void);

/**********************************************************************************
Function	: 	bpi_deinit
Description : 	This function deinitialization bpi
Input		: 	NONE
Output		: 	NONE
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example		:
				// call bpi api
				bpi_deinit()

***********************************************************************************/
BPI_API int bpi_deinit(void);

/**********************************************************************************
Function	: 	bpi_report_release_info
Description : 	This function gets BPI version information and release date
Input  		: 	NONE
Output 		: 	
				info
				[out]: at least 128 bytes are required
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example		:
				char info[128];
				if (BPI_SUCCESS == bpi_bpi_report_release_info(&info)) {
					printf("BPI Info: %s\n", info);
				}
***********************************************************************************/
BPI_API int bpi_report_release_info(char *info);

/**********************************************************************************
Function	: 	bpi_get_gpio_number
Description : 	Get BPI version information and release date
Input  		:
				Null
Output 		: 	Null
Return value: 	number:gpio number
Example:
				// Get number
				
				(number)

***********************************************************************************/
BPI_API int bpi_get_gpio_number(void);

/**********************************************************************************
Function	: 	bpi_set_gpio_mode
Description : 	This function set the specified gpio to output or input mode
Input  		:
				pin
				[in]: BPI_GPIO_1 - BPI_GPIO_32
				mode
				[in]: BPI_GPIO_OUTPUT or BPI_GPIO_INPUT
Output 		: 	NONE
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example:
				// Set GPIO1 to output mode
				bpi_set_gpio_mode(BPI_GPIO_1, BPI_GPIO_OUTPUT)

***********************************************************************************/
BPI_API int bpi_set_gpio_mode(int pin, UINT8 mode);

/**********************************************************************************
Function	: 	bpi_set_gpio_output_level
Description : 	This function sets the specified gpio pin output level
Input  		:
				pin
				[in]: BPI_GPIO_1 - BPI_GPIO_32
				level
				[in]: BPI_GPIO_HIGH_LEVEL or BPI_GPIO_LOW_LEVEL
Output 		: 	NONE
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example:
				// Set GPIO1 output level to high
				bpi_set_gpio_output_level(BPI_GPIO_1, BPI_GPIO_HIGH_LEVEL);
***********************************************************************************/
BPI_API int bpi_set_gpio_output_level(int pin, UINT8 level);

/**********************************************************************************
Function	: 	bpi_get_gpio_level
Description : 	This function gets the specified gpio pin input level
Input  		:
				pin
				[in]: BPI_GPIO_1 - BPI_GPIO_32
Output 		:
				level: BPI_GPIO_HIGH_LEVEL or BPI_GPIO_LOW_LEVEL
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example		:
				// get GPIO1 input level
				UINT8 level;
				bpi_get_gpio_level(BPI_GPIO_1, &level);
***********************************************************************************/
BPI_API int bpi_get_gpio_level(int pin, UINT8 *level);

/**********************************************************************************
Function	: 	bpi_start_watchdog
Description : 	This function sets and start a watchdog
Input  		:
				timeout
				[in]: time parameter(1-255)
				watchdog_mode
				[in]: BPI_WATCHDOG_SECOND_MODE or BPI_WATCHDOG_MINUTE_MODE
Output 		: 	NONE
Return value:	BPI_SUCCESS or BPI_FAILURE
Example		:
				// set the watchdog timeout time to 10 seconds, and the time unit is 
				seconds
				bpi_start_watch(10, BPI_WATCHDOG_SECOND_MODE)
***********************************************************************************/
BPI_API int bpi_start_watchdog(UINT8 timeout, UINT8 watchdog_mode);

/**********************************************************************************
Function	: 	bpi_feed_watchdog
Description : 	This function feeding the watchdog
Input  		:
				timeout
				[in]: feeding time(1-255)
Output 		: 	NONE
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example		:
			// feeding 10
			bpi_feed_watchdog(10);
***********************************************************************************/
BPI_API int bpi_feed_watchdog(UINT8 timeout);

/**********************************************************************************
Function	: 	bpi_stop_watchdog
Description : 	This funcion stop a watchdog
Input  		: 	NONE
Output 		: 	NONE
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example		:
			// stop watchdog funcction
			bpi_stop_watchdog();
***********************************************************************************/
BPI_API int bpi_stop_watchdog(void);

/**********************************************************************************
Function	: 	bpi_turn_on_beep
Description : 	turn on beep
Input  		:   NONE
Output 		: 	NONE
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example		:
                // turn beep
                bpi_turn_on_beep();
***********************************************************************************/
BPI_API int bpi_turn_on_beep(void);

/**********************************************************************************
Function	: 	bpi_turn_off_beep
Description : 	This function turn the beep off
Input  		: 	NONE
Output 		: 	NONE
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example		:
				// turn off beep
				bpi_turn_off_beep
***********************************************************************************/
BPI_API int bpi_turn_off_beep(void);

/**********************************************************************************
Function	: 	bpi_get_watchdog_current_timeout_value
Description : 	This function gets the left time from watchdog
Input  		:
Output 		: 	timeout
				[in]: how much time is left
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example		:
				// get timeout value
				UINT16 time_left
				bpi_get_watchdog_current_timeout_value(&time_left);
***********************************************************************************/
BPI_API int bpi_get_watchdog_current_timeout_value(UINT16 *timeout);

/**********************************************************************************
Function	: 	bpi_get_hhm_temperature
Description : 	This function gets the specified CPU and system temperature
Input  		:
				number
				[in]: BPI_CPU1_TEMP, BPI_CPU2_TEMP, BPI_SYS_TEMP
Output 		:
				temperature
				[out]: acquired temperature value
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example		:
				// get CPU1 temperature
				UINT8 temp;
				bpi_get_hhm_temperature(BPI_CPU1_TEMP, &temp);
***********************************************************************************/
BPI_API int bpi_get_hhm_temperature(UINT8 number, UINT8 *temperature);

/**********************************************************************************
Function	: 	bpi_get_hhm_voltage
Description : 	This function gets the specified system voltage
Input  		:
				number
				[in]: BPI_VCC_12 BPI_VCC_5 BPI_VCC_CORE BPI_VCC_1_2_DDQ BPI_VCC_3_3
					  BPI_VCC_BAT
Output 		:
				voltage
				[out]: acquired voltage value
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example		:
				// get BPI_VCC_12 voltage
				float vol;
				bpi_get_hhm_voltage(BPI_VCC_12, &vol);
***********************************************************************************/
BPI_API int bpi_get_hhm_voltage(UINT8 number, float *voltage);

/**********************************************************************************
Function	: 	bpi_get_fan_speed
Description : 	This function gets the specified fan speed
Input  		:
				number
				[in]: BPI_CPU1_FAN BPI_CPU2_FAN BPI_SYS1_FAN
Output 		:
				rpm: acquired fan value
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example		:
				// get BPI_CPU1_FAN fan speen
				UINT16 rpm;
				bpi_get_hhm_voltage(BPI_VCC_12, &rpm);
***********************************************************************************/
BPI_API int bpi_get_fan_speed(UINT8 number, UINT16 *rpm);

/**********************************************************************************
Function	: 	bpi_led_on
Description : 	This function turn the specified led on
Input  		:
				led_pin
				[in]: BPI_LED_1 BPI_LED_2 BPI_LED_3 BPI_LED_4 BPI_LED_5
Output 		: 	NONE
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example		:
				// set led run on
				bpi_led_on(BPI_LED_1);
***********************************************************************************/
BPI_API int bpi_led_on(int led_num);

/**********************************************************************************
Function	: 	bpi_led_off
Description : 	This function turn the specified led off
Input  		:
				led_pin
				[in]: BPI_LED_1 BPI_LED_2 BPI_LED_3 BPI_LED_4 BPI_LED_5
Output 		: 	NONE
Return value: 	BPI_SUCCESS or BPI_FAILURE
Example		:
				// set led run off
				bpi_led_off(BPI_LED_1);
***********************************************************************************/
BPI_API int bpi_led_off(int led_num);

#endif
