 /***
 *      ____    ____  _  ____   ____    ___   __  __ 
 *     / ___|  / ___|(_)|  _ \ |  _ \  / _ \ |  \/  |
 *     \___ \ | |    | || | | || |_) || | | || |\/| |
 *      ___) || |___ | || |_| ||  _ < | |_| || |  | |
 *     |____/  \____||_||____/ |_| \_\ \___/ |_|  |_|
 *        (C)2018 Scidrom 
 
	Description: MAG3110 driver
	License: GNU General Public License
	Maintainer: S54MTB
*/

/******************************************************************************
  * @file    veml6075.h
  * @author  S54MTB
  * @version V1.0.0
  * @date    12-January-2018
  * @brief   veml6075 driver header file
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
  * along with this program.  If not, see <https://www.gnu.org/licenses/>.  *
  ******************************************************************************
  */


#ifndef __VEML6075__
#define __VEML6075__

#include "stm32l0xx_hal.h"
#include "stdint.h"
#include "stdbool.h"

/**!
	* VEML6075 I2C Slave address
	*/
#define VEML6075ADDRESS				0x10

/**!
	* VEML6075 data registers
	*/
#define VEML6075_UV_CONF			0x00
#define VEML6075_UVA_DATA			0x07
#define VEML6075_UVB_DATA			0x09
#define VEML6075_UVCOMP1_DATA	0x0a
#define VEML6075_UVCOMP2_DATA	0x0b
#define VEML6075_ID						0x0c

#define VEML6075_IDRESPONSE		0x0026

/**!
	*	Register values define : CONF */
#define VEML6075_CONF_SD 0x01
#define VEML6075_CONF_UV_AF_AUTO 0x00
#define VEML6075_CONF_UV_AF_FORCE 0x02
#define VEML6075_CONF_UV_TRIG_NO 0x00
#define VEML6075_CONF_UV_TRIG_ONCE 0x04
#define VEML6075_CONF_HD 0x08
#define VEML6075_CONF_UV_IT_MASK 0x70
#define VEML6075_CONF_UV_IT_50MS 0x00
#define VEML6075_CONF_UV_IT_100MS 0x10
#define VEML6075_CONF_UV_IT_200MS 0x20
#define VEML6075_CONF_UV_IT_400MS 0x30
#define VEML6075_CONF_UV_IT_800MS 0x40
#define VEML6075_CONF_DEFAULT (VEML6075_CONF_UV_AF_AUTO | VEML6075_CONF_UV_TRIG_NO | VEML6075_CONF_UV_IT_100MS)


typedef enum
{
	VEML6075_PARAM_UVA,
	VEML6075_PARAM_UVB,
	VEML6075_PARAM_UVCOMP1,
	VEML6075_PARAM_UVCOMP2
} VEML6075_PARAM_t;

HAL_StatusTypeDef VEML6075_WhoAmI( I2C_HandleTypeDef *hi2c, uint16_t *idval );
HAL_StatusTypeDef VEML6075_ShutDown( I2C_HandleTypeDef *hi2c, bool sd ) ;
HAL_StatusTypeDef VEML6075_UVVAL( I2C_HandleTypeDef *hi2c, VEML6075_PARAM_t param, uint16_t *val );

#endif


