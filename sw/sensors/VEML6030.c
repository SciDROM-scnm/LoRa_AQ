 /***
 *      ____    ____  _  ____   ____    ___   __  __ 
 *     / ___|  / ___|(_)|  _ \ |  _ \  / _ \ |  \/  |
 *     \___ \ | |    | || | | || |_) || | | || |\/| |
 *      ___) || |___ | || |_| ||  _ < | |_| || |  | |
 *     |____/  \____||_||____/ |_| \_\ \___/ |_|  |_|
 *        (C)2018 Scidrom 
 
	Description: VEML6030 driver
	License: GNU General Public License
	Maintainer: S54MTB
*/

/******************************************************************************
  * @file    VEML6030.c
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

#include "veml6030.h"


/*
 * The VEML6030 contains actual six 16 bit command codes for operation control, 
 * parameter setup, and result buffering. All registers are accessible 
 * via I2C communication.
 */

/*
 * VEML6030_ReadRegister() - Read register from VEML6030
 * @hi2c:  handle to I2C interface
 * @adr: I2C device address
 * @reg: Register address
 * @val: 16-bit register value from the VEML6030
 * Returns HAL status or HAL_ERROR for invalid parameters.
 */
static HAL_StatusTypeDef VEML6030_ReadRegister(I2C_HandleTypeDef *hi2c, 
						uint8_t adr, uint8_t reg, uint16_t *regval)
{
//	uint8_t val[2];
//	HAL_StatusTypeDef status;
//	
////	status = HAL_I2C_Mem_Read(hi2c, adr<<1, reg , I2C_MEMADD_SIZE_8BIT, val, 2, 0);

//  // first set the I2C bus slave address byte and 8 bit Command code
//	HAL_I2C_Master_Transmit(hi2c, adr<<1, &reg, 1, 100);
//  
//	// receive the 2 x 8bit data into the receive buffer 
//	status = HAL_I2C_Master_Receive(hi2c, adr<<1 | 0x01, val, 2, 100);
//	
//	if (status == HAL_OK)
//	{
//		*regval = val[0] | val[1] << 8;
//	}
//	return status;
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
 * VEML6030_WriteRegister() - Write VEML6030 register
 * @hi2c:  handle to I2C interface
 * @adr: I2C device address
 * @reg: Register address
 * @val: 8-bit register value from the VEML6030
 * Returns HAL status or HAL_ERROR for invalid parameters.
 */
static HAL_StatusTypeDef VEML6030_WriteRegister(I2C_HandleTypeDef *hi2c, 
				uint8_t adr, uint8_t reg, uint16_t regval)
{	
	uint8_t val[2];
	uint16_t retreg;
	
	val[1] = (regval >> 8) & 0xff;
	val[0] = regval & 0xff;
	HAL_StatusTypeDef status = HAL_I2C_Mem_Write(hi2c, adr<<1, reg, 
			I2C_MEMADD_SIZE_8BIT, val, 2, 100);
	
	VEML6030_ReadRegister(hi2c, adr, reg, &retreg);
	
	if (retreg != regval) 
		return HAL_ERROR;
	
	return status;
}


/*
 * VEML6030_Init() - Write VEML6030 register
 * @hi2c:  handle to I2C interface
 * @adr: I2C device address
 * @reg: Register address
 * @val: 8-bit register value from the VEML6030
 * Returns HAL status or HAL_ERROR for invalid parameters.
 */
HAL_StatusTypeDef VEML6030_Init(I2C_HandleTypeDef *hi2c, 
				uint8_t adr)
{	
	uint8_t val[2] = {0,0};
	
	HAL_StatusTypeDef status = HAL_I2C_Mem_Write(hi2c, adr<<1, VEML6030_ALS_CONF, 
			I2C_MEMADD_SIZE_8BIT, val, 2, 100);
	
	return status;
}



/*
 * VEML6030_Configure() - Write VEML6030 ALS gain, integration time, interrupt, and shut down
 * @hi2c:  handle to I2C interface
 * @adr: I2C device address
 * @conf: Configuration Register value
 * Returns HAL status or HAL_ERROR for invalid parameters.
 */
HAL_StatusTypeDef VEML6030_Configure(I2C_HandleTypeDef *hi2c, 
				uint8_t adr, veml6030_config_t conf)
{	
	return VEML6030_WriteRegister(hi2c, adr, VEML6030_ALS_CONF, conf.r);
}


/*
 * VEML6030_SetWindow() - Write VEML6030 Tresholds
 * @hi2c:  handle to I2C interface
 * @adr: I2C device address
 * @low: Low Threshold Windows Setting
 * @high: High Threshold Windows Setting
 * Returns HAL status or HAL_ERROR for invalid parameters.
 */
HAL_StatusTypeDef VEML6030_Window(I2C_HandleTypeDef *hi2c, 
				uint8_t adr, uint16_t low, uint16_t high)
{	
	HAL_StatusTypeDef status = 
	  VEML6030_WriteRegister(hi2c, adr, VEML6030_ALS_WL, low);
	if (status != HAL_OK) return status;
	return VEML6030_WriteRegister(hi2c, adr, VEML6030_ALS_WH, high);
}



/*
 * VEML6030_PowerSavingMode() - Write VEML6030 PSM
 * @hi2c:  handle to I2C interface
 * @adr: I2C device address
 * @psm: Configuration Register value
 * Returns HAL status or HAL_ERROR for invalid parameters.
 */
HAL_StatusTypeDef VEML6030_PowerSavingMode(I2C_HandleTypeDef *hi2c, 
				uint8_t adr, uint8_t mode, bool enable)
{	
	uint16_t regval = (mode & 0x03) << 1 | enable;
	return VEML6030_WriteRegister(hi2c, adr, VEML6030_Powersaving, regval);
}



/*
 * VEML6030_ReadALS() - Read High Resolution Output Data
 * @hi2c:  handle to I2C interface
 * @adr: I2C device address
 * als: ALS high resolution output data
 * Returns HAL status or HAL_ERROR for invalid parameters.
 */
HAL_StatusTypeDef VEML6030_ReadALS(I2C_HandleTypeDef *hi2c, 
				uint8_t adr, uint16_t *als)
{	
	return VEML6030_ReadRegister(hi2c, adr, VEML6030_ALS, als);
}



/*
 * VEML6030_ReadWhite() - Read White Channel Output Data
 * @hi2c:  handle to I2C interface
 * @adr: I2C device address
 * white: WHITE output data
 * Returns HAL status or HAL_ERROR for invalid parameters.
 */
HAL_StatusTypeDef VEML6030_ReadWhite(I2C_HandleTypeDef *hi2c, 
				uint8_t adr, uint16_t *white)
{	
	return VEML6030_ReadRegister(hi2c, adr, VEML6030_WHITE, white);
}


/*
 * VEML6030_ReadInt() - Read Interrupt Status
 * @hi2c:  handle to I2C interface
 * @adr: I2C device address
 * lo: Indicates a low threshold exceed
 * hi: Indicates a high threshold exceed
 * Returns HAL status or HAL_ERROR for invalid parameters.
 */
HAL_StatusTypeDef VEML6030_ReadInt(I2C_HandleTypeDef *hi2c, 
				uint8_t adr, bool *lo, bool *hi)
{	
	uint16_t regval;
	HAL_StatusTypeDef status =
					VEML6030_ReadRegister(hi2c, adr, VEML6030_ALS_INT, &regval);
	if (status == HAL_OK)
	{
		*lo = regval & 0x8000;
		*hi = regval & 0x4000;
		
	}
	return status;
}








