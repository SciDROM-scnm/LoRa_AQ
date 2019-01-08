 /***
 *      ____    ____  _  ____   ____    ___   __  __ 
 *     / ___|  / ___|(_)|  _ \ |  _ \  / _ \ |  \/  |
 *     \___ \ | |    | || | | || |_) || | | || |\/| |
 *      ___) || |___ | || |_| ||  _ < | |_| || |  | |
 *     |____/  \____||_||____/ |_| \_\ \___/ |_|  |_|
 *        (C)2018 Scidrom 
 
	Description: VEML6075 driver
	License: GNU General Public License
	Maintainer: S54MTB
*/

/******************************************************************************
  * @file    VEML6030.h
  * @author  S54MTB
  * @version V1.0.0
  * @date    14-January-2018
  * @brief   VEML6030 driver
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 Scidrom 
	* This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
	*
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <https://www.gnu.org/licenses/>.  
  ******************************************************************************
  */

#ifndef __VEML6030_H__
#define __VEML6030_H__

#include "stm32l0xx_hal.h"
#include "stdint.h"
#include "stdbool.h"

/** VEML6030 I2C slave address ... uncomment per ADDR pin level  */
//#define VEML6030_ADDR	0x48		// I2Caddrress when ADDR Hi
#define VEML6030_ADDR	0x10		// I2Caddrress when ADDR Lo


/** VEML6030 command codes */

#define VEML6030_ALS_CONF 				0x00
#define VEML6030_ALS_WH						0x01
#define VEML6030_ALS_WL						0x02
#define VEML6030_Powersaving			0x03
#define VEML6030_ALS							0x04
#define VEML6030_WHITE						0x05
#define VEML6030_ALS_INT					0x06

// Gain settings 1, 2, 1/8, 1/4
#define VEML6030_ALS_GAIN1				0x00
#define VEML6030_ALS_GAIN2				0x01
#define VEML6030_ALS_GAIN1_8			0x02
#define VEML6030_ALS_GAIN1_4			0x03

// Integration time 25, 50, 100, 200, 400, 800 ms
#define VEML6030_ALS_IT25					0x0c
#define VEML6030_ALS_IT50					0x08
#define VEML6030_ALS_IT100				0x00
#define VEML6030_ALS_IT200				0x01
#define VEML6030_ALS_IT400				0x02
#define VEML6030_ALS_IT800				0x03

// ALS persistence protect number setting
#define VEML6030_ALS_PERS1				0x00
#define VEML6030_ALS_PERS2				0x01
#define VEML6030_ALS_PERS4				0x02
#define VEML6030_ALS_PERS8				0x03

// ALS interrupt enable setting
#define VEML6030_ALS_INT_ENABLED	0x01
#define VEML6030_ALS_INT_DISABLED 0x00

// ALS shut down setting
#define VEML6030_ALS_SD_POWERON		0x00
#define VEML6030_ALS_SD_SHUTDOWN	0x01


/** \brief  Union type for the structure of CONFIGURATION REGISTER in VEML6030
 */
typedef union
{
	struct
	{
			uint16_t ALS_SD				:1;  		/*!< bit:  0   ALS shut down setting */
			uint16_t ALS_INT_EN		:1;  		/*!< bit:  1   ALS interrupt enable setting */
			uint16_t     					:2;  		/*!< bit:  2:3 reserved */
			uint16_t ALS_PERS			:2;  		/*!< bit:  4:5 ALS persistence protect number setting */
			uint16_t ALS_IT     		:4;  		/*!< bit:  6:9 ALS integration time setting */
			uint16_t     					:1;  		/*!< bit:  10 reserved */
			uint16_t ALS_GAIN 			:2;  		/*!< bit:  11:12 Gain selection */
			uint16_t     					:3;  		/*!< bit:  13:15 reserved */
	} b;
	uint16_t r;
} veml6030_config_t;



HAL_StatusTypeDef VEML6030_Configure(I2C_HandleTypeDef *hi2c, 
				uint8_t adr, veml6030_config_t conf);

HAL_StatusTypeDef VEML6030_Window(I2C_HandleTypeDef *hi2c, 
				uint8_t adr, uint16_t low, uint16_t high);

HAL_StatusTypeDef VEML6030_PowerSavingMode(I2C_HandleTypeDef *hi2c, 
				uint8_t adr, uint8_t mode, bool enable);

HAL_StatusTypeDef VEML6030_ReadALS(I2C_HandleTypeDef *hi2c, 
				uint8_t adr, uint16_t *als);

HAL_StatusTypeDef VEML6030_ReadWhite(I2C_HandleTypeDef *hi2c, 
				uint8_t adr, uint16_t *white);

HAL_StatusTypeDef VEML6030_ReadInt(I2C_HandleTypeDef *hi2c, 
				uint8_t adr, bool *lo, bool *hi);

HAL_StatusTypeDef VEML6030_Init(I2C_HandleTypeDef *hi2c, 
	      uint8_t adr);
#endif


