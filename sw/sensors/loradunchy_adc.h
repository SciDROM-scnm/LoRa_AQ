 /***
 *      ____    ____  _  ____   ____    ___   __  __ 
 *     / ___|  / ___|(_)|  _ \ |  _ \  / _ \ |  \/  |
 *     \___ \ | |    | || | | || |_) || | | || |\/| |
 *      ___) || |___ | || |_| ||  _ < | |_| || |  | |
 *     |____/  \____||_||____/ |_| \_\ \___/ |_|  |_|
 *        (C)2018 Scidrom 
 
	Description: ADC driver
	License: GNU General Public License
	Maintainer: S54MTB
*/

/******************************************************************************
  * @file    loradunchy_ADC.h
  * @author  S54MTB
  * @version V1.0.0
  * @date    12-January-2018
  * @brief   ADC driver header file
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


#ifndef __loradunchy_ADC__
#define __loradunchy_ADC__

#include "stm32l0xx_hal.h"

uint16_t loradunchy_ADC_GetValue(uint8_t ch);
void loradunchy_adc_start(void);
void loradunchy_adc_init(void);





#endif


