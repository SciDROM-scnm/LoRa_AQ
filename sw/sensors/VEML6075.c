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
  * @file    VEML6075.c
  * @author  S54MTB
  * @version V1.0.0
  * @date    14-January-2018
  * @brief   VEML6075 driver
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

#include "veml6075.h"

/*
 * The VEML6075 has 16-bit registers used to set up the measurements as 
 * well as pick up the measurement results.
 */

/*
 * VEML6075_ReadRegister() - Read register from VEML6075
 * @hi2c:  handle to I2C interface
 * @adr: I2C device address
 * @reg: Register address
 * @val: 16-bit register value from the VEML6075
 * Returns HAL status or HAL_ERROR for invalid parameters.
 */
static HAL_StatusTypeDef VEML6075_ReadRegister(I2C_HandleTypeDef *hi2c, 
						uint8_t adr, uint8_t reg, uint16_t *regval)
{
	uint8_t val[2];
	HAL_StatusTypeDef status;
	
	status = HAL_I2C_Mem_Read(hi2c, adr<<1, reg , I2C_MEMADD_SIZE_8BIT, val, 2, 100);

	if (status == HAL_OK)
	{
		*regval = val[0] | val[1] << 8;
	}
	return status;
}

/*
 * VEML6075_WriteRegister() - Write VEML6075 register
 * @hi2c:  handle to I2C interface
 * @adr: I2C device address
 * @reg: Register address
 * @val: 8-bit register value from the VEML6075
 * Returns HAL status or HAL_ERROR for invalid parameters.
 */
static HAL_StatusTypeDef VEML6075_WriteRegister(I2C_HandleTypeDef *hi2c, 
				uint8_t adr, uint8_t reg, uint16_t regval)
{	
	uint8_t val[2];
	val[1] = (regval >> 8) & 0xff;
	val[0] = regval & 0xff;
	HAL_StatusTypeDef status = HAL_I2C_Mem_Write(hi2c, adr<<1, reg, 
			I2C_MEMADD_SIZE_8BIT, val, 2, 100);
	return status;
}

HAL_StatusTypeDef VEML6075_WhoAmI( I2C_HandleTypeDef *hi2c, uint16_t *idval )
{
	return VEML6075_ReadRegister(hi2c, VEML6075ADDRESS, VEML6075_ID, idval); 
}


HAL_StatusTypeDef VEML6075_UVVAL( I2C_HandleTypeDef *hi2c, VEML6075_PARAM_t param, uint16_t *val )
{
	switch (param)
	{
		case VEML6075_PARAM_UVA:
			return VEML6075_ReadRegister(hi2c, VEML6075ADDRESS, VEML6075_UVA_DATA, val); 
		//break;

		case VEML6075_PARAM_UVB:
			return VEML6075_ReadRegister(hi2c, VEML6075ADDRESS, VEML6075_UVB_DATA, val); 
		//break;

		case VEML6075_PARAM_UVCOMP1:
			return VEML6075_ReadRegister(hi2c, VEML6075ADDRESS, VEML6075_UVCOMP1_DATA, val); 
		//break;

		case VEML6075_PARAM_UVCOMP2:
			return VEML6075_ReadRegister(hi2c, VEML6075ADDRESS, VEML6075_UVCOMP2_DATA, val); 
		//break;
	}
	
	// invalid parameter if we reached here
	return HAL_ERROR;
}


HAL_StatusTypeDef VEML6075_ShutDown( I2C_HandleTypeDef *hi2c, bool sd )
{
	uint16_t regval = VEML6075_CONF_DEFAULT | (sd ? VEML6075_CONF_SD : 0);
	
	return VEML6075_WriteRegister(hi2c, VEML6075ADDRESS, VEML6075_UV_CONF, regval); 
}




