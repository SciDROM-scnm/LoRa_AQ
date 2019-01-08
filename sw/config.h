 /***
 *      ____    ____  _  ____   ____    ___   __  __ 
 *     / ___|  / ___|(_)|  _ \ |  _ \  / _ \ |  \/  |
 *     \___ \ | |    | || | | || |_) || | | || |\/| |
 *      ___) || |___ | || |_| ||  _ < | |_| || |  | |
 *     |____/  \____||_||____/ |_| \_\ \___/ |_|  |_|
 *        (C)2018 Scidrom 
 
	Description: Device configuration all in one place
	License: GNU General Public License
	Maintainer: S54MTB
*/

/*!
 * \file      config.h
 *
 * \brief     Device configuration file
 *
 * \copyright Revised BSD License, see section \ref LICENSE.
 *
 * \code
 *                ______                              _
 *               / _____)             _              | |
 *              ( (____  _____ ____ _| |_ _____  ____| |__
 *               \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 *               _____) ) ____| | | || |_| ____( (___| | | |
 *              (______/|_____)_|_|_| \__)_____)\____)_| |_|
 *              (C)2013-2017 Semtech
 *
 * \endcode
 *
 * \author    Miguel Luis ( Semtech )
 *
 * \author    Gregory Cristian ( Semtech )
*/
/**
  ******************************************************************************
  * @file    config.h
  * @author  MCD Application Team
  * @brief   End device commissioning parameters
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LORA_CONFIG_H__
#define __LORA_CONFIG_H__

#ifdef __cplusplus
 extern "C" {
#endif
/*!
 ******************************************************************************
 ********************************** WARNING ***********************************
 ******************************************************************************
  The crypto-element implementation supports both 1.0.x and 1.1.x LoRaWAN 
  versions of the specification.
  Thus it has been decided to use the 1.1.x keys and EUI name definitions.
  The below table shows the names equivalence between versions:
               +-------------------+-------------------------+
               |       1.0.x       |          1.1.x          |
               +===================+=========================+
               | LORAWAN_DEVICE_EUI| LORAWAN_DEVICE_EUI      |
               +-------------------+-------------------------+
               | LORAWAN_APP_EUI   | LORAWAN_JOIN_EUI        |
               +-------------------+-------------------------+
               | N/A               | LORAWAN_APP_KEY         |
               +-------------------+-------------------------+
               | LORAWAN_APP_KEY   | LORAWAN_NWK_KEY         |
               +-------------------+-------------------------+
               | LORAWAN_NWK_S_KEY | LORAWAN_F_NWK_S_INT_KEY |
               +-------------------+-------------------------+
               | LORAWAN_NWK_S_KEY | LORAWAN_S_NWK_S_INT_KEY |
               +-------------------+-------------------------+
               | LORAWAN_NWK_S_KEY | LORAWAN_NWK_S_ENC_KEY   |
               +-------------------+-------------------------+
               | LORAWAN_APP_S_KEY | LORAWAN_APP_S_KEY       |
               +-------------------+-------------------------+
 ******************************************************************************
 ******************************************************************************
 ******************************************************************************
 */


/**
  Some helper functions for configuration wizard
**/
  
#define _GPIO_PIN_CAT(pin) GPIO_PIN_ ## pin
#define _GPIO_PIN_CON(pin)  _GPIO_PIN_CAT(pin)

#define GPIO1 GPIOA
#define GPIO2 GPIOB
#define GPIO3 GPIOC
#define GPIO4 GPIOD
#define GPIO8 GPIOH

#define _GPIO_PORT_CONV(port) GPIO ## port
#define _GPIO_PORT_CON(port)  _GPIO_PORT_CONV(port)  




//*** <<< Use Configuration Wizard in Context Menu >>> ***

//  <h> Over-the-Air activation
//     <q> OTA
//      <i> 1 - the application uses the Over-the-Air activation procedure. 
//      <i> 0 - the application uses the Personalization activation procedure.
#define OVER_THE_AIR_ACTIVATION                     1

//     <q> Public network
//     <i> Indicates if the end-device is to be connected to a private or public network
#define LORAWAN_PUBLIC_NETWORK_CHK                  1

#if (LORAWAN_PUBLIC_NETWORK_CHK == 1)
  #define LORAWAN_PUBLIC_NETWORK                      true
#else 
  #define LORAWAN_PUBLIC_NETWORK                      false
#endif
#undef   LORAWAN_PUBLIC_NETWORK_CHK
  
//     <q> Static device EUI
//     <i> 1 - static, 0 - automatically generated
#define STATIC_DEVICE_EUI                  1
 
//    <s> Device EUI
//    <i> Application Unique Identifier
#define DEVEUISTR  "393032356F377D04"

//    <s> App EUI
//    <i>Device Unique Identifier
#define JOINEUISTR  "70B3D57ED000B426"
  
//    <s> Application KEY
//    <i> Application KEY
#define APPKEYSTR  "2B7E151628AED2A6ABF7158809CF4F3C"
  
//    <s> Network root key
//    <i> FOR 1.0.x DEVICES IT IS THE LORAWAN_APP_KEY
#define NWKKEYSTR  "2B7E151628AED2A6ABF7158809CF4F3C"
//   </h>
  
#if( OVER_THE_AIR_ACTIVATION == 0 )
//    <h> Personalization activation 
//    <s> Network Session key
//    <i> Network session integrity key
#define NWKSESSIONKEYSTR  "393032356F377D04393032356F377D04"
  
//    <s> App Session Key
//    <i> Application session key
#define APPSESSIONKEYSTR  "393032356F377D04393032356F377D04"

//     <o>network ID <0x00000000-0xffffffff>
//     <i>Default: 0x00
#define LORAWAN_NETWORK_ID                                 ( uint32_t )0x00000000

//     <q> Static device address
//      <i> 1 - DevAdd is LORAWAN_DEVICE_ADDRESS. 
//      <i> 0 - DevAdd is automatically generated using  a pseudo random number
#define STATIC_DEVICE_ADDRESS                     1


//     <o>Device address on the network (big endian) <0x00000000-0xffffffff>
//     <i>Default: 0x0100000a
#define LORAWAN_DEVICE_ADDRESS                      ( uint32_t )0x0100000a

#endif /* OVER_THE_AIR_ACTIVATION == 0 */
// </h>


//     <o> Application duty cycle <10000-999999>
//     <i> Defines the application data transmission duty cycle. Value in [ms].
#define APP_TX_DUTYCYCLE                            10000

//     <q> Adaptive data rate
//     <i> Please note that when ADR is enabled the end-device should be static
#define LORAWAN_ADR_STATE 1

//     <o> LoRaWAN Default data Rate
//      <i> LORAWAN_DEFAULT_DATA_RATE is used only when ADR is disabled
//       <0=> DR_0
//       <1=> DR_1
//       <2=> DR_2
//       <3=> DR_3
//       <4=> DR_4
//       <5=> DR_5
//       <6=> DR_6
//       <7=> DR_7
//       <8=> DR_8
//       <9=> DR_9
//       <10=> DR_10
//       <11=> DR_11
//       <12=> DR_12
//       <13=> DR_13
//       <14=> DR_14
//       <15=> DR_15
#define LORAWAN_DEFAULT_DATA_RATE 0

//      <o> LoRaWAN application port <0-255> 
//      <i> Do not use 224. It is reserved for certification
#define LORAWAN_APP_PORT                            2


//      <o>LoRaWAN endNode class
//      <0=> Class A
//      <1=> Class B
//      <2=> Class C
#define __LORAWAN_DEFAULT_CLASS                       0
 
#if (__LORAWAN_DEFAULT_CLASS == 0) 
  #define LORAWAN_DEFAULT_CLASS CLASS_A
#elif (__LORAWAN_DEFAULT_CLASS == 1) 
  #define LORAWAN_DEFAULT_CLASS CLASS_B
#elif (__LORAWAN_DEFAULT_CLASS == 2) 
  #define LORAWAN_DEFAULT_CLASS CLASS_C
#endif 

 
//      <q>LoRaWAN Message confirmation
#define __LORAWAN_DEFAULT_CONFIRM_MSG_STATE   0

#if (__LORAWAN_DEFAULT_CONFIRM_MSG_STATE == 0)
  #define LORAWAN_DEFAULT_CONFIRM_MSG_STATE           LORAWAN_UNCONFIRMED_MSG
#else
  #define LORAWAN_DEFAULT_CONFIRM_MSG_STATE           LORAWAN_CONFIRMED_MSG
#endif


//      <o> LoRaWAN Region
//      <0=> AS923
//      <1=> AU915
//      <2=> CN470
//      <3=> CN779
//      <4=> EU433
//      <5=> EU868
//      <6=> KR920
//      <7=> IN865
//      <8=> US915
//      <9=> RU864
#define __REGION 5

#if (__REGION == 0)
  #define REGION_AS923
#elif (__REGION == 1)
  #define REGION_AU915
#elif (__REGION == 2)
  #define REGION_CN470
#elif (__REGION == 3)
  #define REGION_CN779
#elif (__REGION == 4)
  #define REGION_EU433
#elif (__REGION == 5)
  #define REGION_EU868
#elif (__REGION == 6)
  #define REGION_KR920
#elif (__REGION == 7)
  #define REGION_IN865
#elif (__REGION == 8)
  #define REGION_US915
#elif (__REGION == 9)
  #define REGION_RU864
#else 
  #error Please define region!
#endif


//  <q>Debug enabled?
#define __DEBUGQ  1

#if (__DEBUGQ == 1) 
  #define DEBUG 1
#endif

//   <h> Sensors
//   <q> HPM Particle sensor
#define HPM_SENSOR 1

//   <q> SI7013 (RH, T)  
#define SI7013_SENSOR 0

//   <q> TMP75 (T)
#define TMP75_SENSOR 0

//   <q> SHT31 (RH, T)
#define SHT31_SENSOR 1

//   <q> BME280 (RH, T, p)
#define BME280_SENSOR 1

//   <q> VEML6030 (UV Index)
#define VEML6030_SENSOR 1

//   <q> VEML6075 (Ambient light)
#define VEML6075_SENSOR 1

// </h>

//   <h> Battery
//   <e> Battery charger 
#define BATTERY_CHARGER 1

//      <o> Charger status port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define CHARGER_STATUS_PORTN 1

//      <o> Charger status Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define CHARGER_STATUS_PINN 10
#define CHARGER_STATUS_PIN     _GPIO_PIN_CON(CHARGER_STATUS_PINN)
#define CHARGER_STATUS_PORT    _GPIO_PORT_CON(CHARGER_STATUS_PORTN)



// </e>

//   <e> STC3100 (Battery fuel gauge)
#define BATTERY_FUEL_GAUGE 1

//   <o> STC3100 RSENSE Resistance in mOhm
//   <i> Sense resistor for fuel gauge in MilliOhms
#define STC3100_RSENSE_RESISTANCE_ME 100
#define STC3100_RSENSE_RESISTANCE  (STC3100_RSENSE_RESISTANCE_ME/1000.0f)


//   </e>

//   <q> Solar power
#define SOLAR_POWER 1

//   <q> Mains power 
#define MAINS_POWER 1

// </h>

//  <h> LoRa radio IO definitions
//      <o> Radio Reset Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_RESET_PORTN 3 

//      <o> Radio Reset Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_RESET_PINN 0
#define RADIO_RESET_PIN     _GPIO_PIN_CON(RADIO_RESET_PINN)
#define RADIO_RESET_PORT    _GPIO_PORT_CON(RADIO_RESET_PORTN)

//      <o> Radio MOSI Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_MOSI_PORTN 1 

//      <o> Radio MOSI Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_MOSI_PINN 7
#define RADIO_MOSI_PIN     _GPIO_PIN_CON(RADIO_MOSI_PINN)
#define RADIO_MOSI_PORT    _GPIO_PORT_CON(RADIO_MOSI_PORTN)

//      <o> Radio MISO Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_MISO_PORTN 1 

//      <o> Radio MISO Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_MISO_PINN 6
#define RADIO_MISO_PIN     _GPIO_PIN_CON(RADIO_MISO_PINN)
#define RADIO_MISO_PORT    _GPIO_PORT_CON(RADIO_MISO_PORTN)

//      <o> Radio SCLK Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_SCLK_PORTN 2 

//      <o> Radio SCLK Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_SCLK_PINN 3
#define RADIO_SCLK_PIN     _GPIO_PIN_CON(RADIO_SCLK_PINN)
#define RADIO_SCLK_PORT    _GPIO_PORT_CON(RADIO_SCLK_PORTN)


//      <o> Radio NSS Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_NSS_PORTN 1 

//      <o> Radio NSS Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_NSS_PINN 15
#define RADIO_NSS_PIN     _GPIO_PIN_CON(RADIO_NSS_PINN)
#define RADIO_NSS_PORT    _GPIO_PORT_CON(RADIO_NSS_PORTN)


//      <o> Radio DIO_0 Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_DIO_0_PORTN 2 

//      <o> Radio DIO_0 Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_DIO_0_PINN 4
#define RADIO_DIO_0_PIN     _GPIO_PIN_CON(RADIO_DIO_0_PINN)
#define RADIO_DIO_0_PORT    _GPIO_PORT_CON(RADIO_DIO_0_PORTN)



//      <o> Radio DIO_1 Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_DIO_1_PORTN 2 

//      <o> Radio DIO_1 Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_DIO_1_PINN 1
#define RADIO_DIO_1_PIN     _GPIO_PIN_CON(RADIO_DIO_1_PINN)
#define RADIO_DIO_1_PORT    _GPIO_PORT_CON(RADIO_DIO_1_PORTN)



//      <o> Radio DIO_2 Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_DIO_2_PORTN 2 

//      <o> Radio DIO_2 Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_DIO_2_PINN 0
#define RADIO_DIO_2_PIN     _GPIO_PIN_CON(RADIO_DIO_2_PINN)
#define RADIO_DIO_2_PORT    _GPIO_PORT_CON(RADIO_DIO_2_PORTN)



//      <o> Radio DIO_3 Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_DIO_3_PORTN 3 

//      <o> Radio DIO_3 Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_DIO_3_PINN 13
#define RADIO_DIO_3_PIN     _GPIO_PIN_CON(RADIO_DIO_3_PINN)
#define RADIO_DIO_3_PORT    _GPIO_PORT_CON(RADIO_DIO_3_PORTN)


//      <e> Radio DIO_4
#define RADIO_DIO_4  0

//      <o> Radio DIO_4 Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_DIO_4_PORTN 1 

//      <o> Radio DIO_4 Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_DIO_4_PINN 5
#define RADIO_DIO_4_PIN     _GPIO_PIN_CON(RADIO_DIO_4_PINN)
#define RADIO_DIO_4_PORT    _GPIO_PORT_CON(RADIO_DIO_4_PORTN)

//   </e>


//      <e> Radio DIO_5
#define RADIO_DIO_5  0

//      <o> Radio DIO_5 Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_DIO_5_PORTN 1 

//      <o> Radio DIO_5 Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_DIO_5_PINN 4
#define RADIO_DIO_5_PIN     _GPIO_PIN_CON(RADIO_DIO_5_PINN)
#define RADIO_DIO_5_PORT    _GPIO_PORT_CON(RADIO_DIO_5_PORTN)

#if (RADIO_DIO_4 == 0) 
  #undef RADIO_DIO_4
#endif

#if (RADIO_DIO_5 == 0) 
  #undef RADIO_DIO_5
#endif

//   </e>


//      <o> Radio TCXO_VCC Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_TCXO_VCC_PORTN 2 

//      <o> Radio TCXO_VCC Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_TCXO_VCC_PINN 2
#define RADIO_TCXO_VCC_PIN     _GPIO_PIN_CON(RADIO_TCXO_VCC_PINN)
#define RADIO_TCXO_VCC_PORT    _GPIO_PORT_CON(RADIO_TCXO_VCC_PORTN)


//      <o> Radio ANT_SWITCH RX Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_ANT_SWITCH_PORT_RXN 1 

//      <o> Radio ANT_SWITCH RX Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_ANT_SWITCH_PIN_RXN 1
#define RADIO_ANT_SWITCH_PIN_RX     _GPIO_PIN_CON(RADIO_ANT_SWITCH_PIN_RXN)
#define RADIO_ANT_SWITCH_PORT_RX    _GPIO_PORT_CON(RADIO_ANT_SWITCH_PORT_RXN)

//      <o> Radio ANT_SWITCH BOOST Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_ANT_SWITCH_PORT_BOOSTN 3 

//      <o> Radio ANT_SWITCH BOOST Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_ANT_SWITCH_PIN_BOOSTN 1
#define RADIO_ANT_SWITCH_PIN_TX_BOOST     _GPIO_PIN_CON(RADIO_ANT_SWITCH_PIN_BOOSTN)
#define RADIO_ANT_SWITCH_PORT_TX_BOOST    _GPIO_PORT_CON(RADIO_ANT_SWITCH_PORT_BOOSTN)
        

//      <o> Radio ANT_SWITCH RFO Port
//      <1=> GPIOA
//      <2=> GPIOB
//      <3=> GPIOC
//      <8=> GPIOH
#define RADIO_ANT_SWITCH_PORT_RFON 3 

//      <o> Radio ANT_SWITCH RFO Pin
//      <0=> GPIO_PIN_0
//      <1=> GPIO_PIN_1
//      <2=> GPIO_PIN_2
//      <3=> GPIO_PIN_3
//      <4=> GPIO_PIN_4
//      <5=> GPIO_PIN_5
//      <6=> GPIO_PIN_6
//      <7=> GPIO_PIN_7
//      <8=> GPIO_PIN_8
//      <9=> GPIO_PIN_9
//      <10=> GPIO_PIN_10
//      <11=> GPIO_PIN_11
//      <12=> GPIO_PIN_12
//      <13=> GPIO_PIN_13
//      <14=> GPIO_PIN_14
//      <15=> GPIO_PIN_15
#define RADIO_ANT_SWITCH_PIN_RFON 2
#define RADIO_ANT_SWITCH_PIN_TX_RFO     _GPIO_PIN_CON(RADIO_ANT_SWITCH_PIN_RFON)
#define RADIO_ANT_SWITCH_PORT_TX_RFO    _GPIO_PORT_CON(RADIO_ANT_SWITCH_PORT_RFON)




//  </h>

// ************************************************************************
//  !!! Please review the source for other hardware assignments !!!
// ************************************************************************


//*** <<< end of configuration section >>>    ***





//#define RADIO_DIO_4
//#define RADIO_DIO_5
   
/* LORA I/O definition */
   
//#define RADIO_RESET_PORT                          GPIOC
//#define RADIO_RESET_PIN                           GPIO_PIN_0

//#define RADIO_MOSI_PORT                           GPIOA
//#define RADIO_MOSI_PIN                            GPIO_PIN_7

//#define RADIO_MISO_PORT                           GPIOA
//#define RADIO_MISO_PIN                            GPIO_PIN_6

//#define RADIO_SCLK_PORT                           GPIOB
//#define RADIO_SCLK_PIN                            GPIO_PIN_3

//#define RADIO_NSS_PORT                            GPIOA
//#define RADIO_NSS_PIN                             GPIO_PIN_15

//#define RADIO_DIO_0_PORT                          GPIOB
//#define RADIO_DIO_0_PIN                           GPIO_PIN_4

//#define RADIO_DIO_1_PORT                          GPIOB
//#define RADIO_DIO_1_PIN                           GPIO_PIN_1

//#define RADIO_DIO_2_PORT                          GPIOB
//#define RADIO_DIO_2_PIN                           GPIO_PIN_0

//#define RADIO_DIO_3_PORT                          GPIOC
//#define RADIO_DIO_3_PIN                           GPIO_PIN_13

//#ifdef RADIO_DIO_4 
//#define RADIO_DIO_4_PORT                          GPIOA
//#define RADIO_DIO_4_PIN                           GPIO_PIN_5
//#endif

//#ifdef RADIO_DIO_5 
//#define RADIO_DIO_5_PORT                          GPIOA
//#define RADIO_DIO_5_PIN                           GPIO_PIN_4
//#endif

/** Modified for LoRaWX Project to PB2 */
//#define RADIO_TCXO_VCC_PORT                       GPIOB
//#define RADIO_TCXO_VCC_PIN                        GPIO_PIN_2

//#define RADIO_ANT_SWITCH_PORT_RX                  GPIOA //CRF1
//#define RADIO_ANT_SWITCH_PIN_RX                   GPIO_PIN_1

//#define RADIO_ANT_SWITCH_PORT_TX_BOOST            GPIOC //CRF3
//#define RADIO_ANT_SWITCH_PIN_TX_BOOST             GPIO_PIN_1

//#define RADIO_ANT_SWITCH_PORT_TX_RFO              GPIOC //CRF2
//#define RADIO_ANT_SWITCH_PIN_TX_RFO               GPIO_PIN_2

/*  SPI MACRO redefinition */

#define SPI_CLK_ENABLE()                __HAL_RCC_SPI1_CLK_ENABLE()

#define SPI1_AF                          GPIO_AF0_SPI1  

/* ADC MACRO redefinition */

#define ADC_READ_CHANNEL                 ADC_CHANNEL_4
#define ADCCLK_ENABLE()                 __HAL_RCC_ADC1_CLK_ENABLE() ;
#define ADCCLK_DISABLE()                __HAL_RCC_ADC1_CLK_DISABLE() ;



/* --------------------------- RTC HW definition -------------------------------- */

#define RTC_OUTPUT       DBG_RTC_OUTPUT

#define RTC_Alarm_IRQn              RTC_IRQn
/* --------------------------- USART HW definition -------------------------------*/
#define USARTx                           USART2
#define USARTx_CLK_ENABLE()              __USART2_CLK_ENABLE();
#define USARTx_RX_GPIO_CLK_ENABLE()      __GPIOA_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()      __GPIOA_CLK_ENABLE() 
#define DMAx_CLK_ENABLE()                __HAL_RCC_DMA1_CLK_ENABLE()

#define USARTx_FORCE_RESET()             __USART2_FORCE_RESET()
#define USARTx_RELEASE_RESET()           __USART2_RELEASE_RESET()


#define USARTx_TX_PIN                  GPIO_PIN_2
#define USARTx_TX_GPIO_PORT            GPIOA  
#define USARTx_TX_AF                   GPIO_AF4_USART2
#define USARTx_RX_PIN                  GPIO_PIN_3
#define USARTx_RX_GPIO_PORT            GPIOA 
#define USARTx_RX_AF                   GPIO_AF4_USART2

/* Definition for USARTx's NVIC */
#define USARTx_IRQn                      USART2_IRQn
#define USARTx_IRQHandler                USART2_IRQHandler

/* Definition for USARTx's DMA */
#define USARTx_TX_DMA_CHANNEL             DMA1_Channel7

/* Definition for USARTx's DMA Request */
#define USARTx_TX_DMA_REQUEST             DMA_REQUEST_4

/* Definition for USARTx's NVIC */
#define USARTx_DMA_TX_IRQn                DMA1_Channel4_5_6_7_IRQn
#define USARTx_DMA_TX_IRQHandler          DMA1_Channel4_5_6_7_IRQHandler

#define USARTx_Priority 10
#define USARTx_DMA_Priority 0

#define LED_Toggle( x )                 BSP_LED_Toggle( x );
#define LED_On( x )                     BSP_LED_On( x );
#define LED_Off( x )                    BSP_LED_Off( x );




#ifdef __cplusplus
}
#endif

#endif /* __LORA_COMMISSIONING_H__ */
