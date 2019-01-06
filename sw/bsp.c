/**
  ******************************************************************************
  * @file    bsp.c
  * @author  S54MTB
  * @brief   manages the sensors and other on-board hardware
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <stdlib.h>
#include "hw.h"
#include "timeServer.h"
#include "bsp.h"


/**
  * @brief  Configures LED GPIO.
  * @param  None
  * @retval None
  */
void BSP_LED_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  /* Enable the GPIO_LED Clock */
  LED_GPIO_CLK_ENABLE();

  /* Configure the GPIO_LED pin */
  GPIO_InitStruct.Pin = LED_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  
  HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);
}


/**
  * @brief  Turns selected LED On.
  * @param  Led: Specifies the Led to be set on. 
  *   This parameter can be one of following parameters:
  *            @arg  LED2
  * @retval None
  */
void BSP_LED_On(void)
{
  HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, GPIO_PIN_SET); 
}

/**
  * @brief  Turns selected LED Off. 
  * @param  Led: Specifies the Led to be set off. 
  *   This parameter can be one of following parameters:
  *            @arg  LED2
  * @retval None
  */
void BSP_LED_Off(void)
{
  HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, GPIO_PIN_RESET); 
}

/**
  * @brief  Toggles the selected LED.
  * @param  Led: Specifies the Led to be toggled. 
  *   This parameter can be one of following parameters:
  *            @arg  LED2
  * @retval None
  */
void BSP_LED_Toggle(void)
{
  HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
}








void BSP_sensor_Read( sensor_t *sensor_data)
{
}

void  BSP_sensor_Init( void  )
{
}

