/*!
 * \file      Commissioning.h
 *
 * \brief     End device commissioning parameters
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
  * @file    commissioning.h
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
#ifndef __LORA_COMMISSIONING_H__
#define __LORA_COMMISSIONING_H__

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

//*** <<< end of configuration section >>>    ***



#ifdef __cplusplus
}
#endif

#endif /* __LORA_COMMISSIONING_H__ */
