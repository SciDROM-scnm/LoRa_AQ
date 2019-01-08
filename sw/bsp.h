/**
  ******************************************************************************
  * @file    bsp.h
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_H__
#define __BSP_H__

#ifdef __cplusplus
 extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "sensors.h"
   
/* Exported types ------------------------------------------------------------*/

#define LED_PIN                           GPIO_PIN_1
#define LED_GPIO_PORT                     GPIOH
#define LED_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOH_CLK_ENABLE()  
#define LED_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOH_CLK_DISABLE()
   

typedef struct{
  uint16_t dummy;
} sensor_t;


/* Exported constants --------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 
/**
 * @brief  initialises the sensor
 *
 * @note
 * @retval None
 */
void  BSP_sensor_Init( void  );

/**
 * @brief  sensor  read. 
 *
 * @note none
 * @retval sensor_data
 */
void BSP_sensor_Read( sensor_t *sensor_data);


void             BSP_LED_Init(void);
void             BSP_LED_On(void);
void             BSP_LED_Off(void);
void             BSP_LED_Toggle(void);                 


#ifdef __cplusplus
}
#endif

#endif /* __BSP_H__ */


