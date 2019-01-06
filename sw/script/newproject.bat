REM Base folder for LoRawan stack files
SET lora_dir=".\STM32CubeExpansion_LRWAN_V1.2.1"

REM Destination source folder
SET src_dir=".\src"

mkdir %src_dir%
mkdir %src_dir%"\lib\"

copy %lora_dir%"\Drivers\BSP\Components\sx1276\*.c" %src_dir%"\lib\"
copy %lora_dir%"\Drivers\BSP\Components\sx1276\*.h" %src_dir%"\lib\"

copy %lora_dir%"\Drivers\BSP\CMWX1ZZABZ-0xx\*.c" %src_dir%"\lib\"
copy %lora_dir%"\Drivers\BSP\CMWX1ZZABZ-0xx\*.h" %src_dir%"\lib\"
copy %lora_dir%"\Drivers\BSP\B-L072Z-LRWAN1\*.c" %src_dir%"\lib\"
copy %lora_dir%"\Drivers\BSP\B-L072Z-LRWAN1\*.h" %src_dir%"\lib\"

copy %lora_dir%"\Drivers\CMSIS\Device\ST\STM32L0xx\Source\Templates\system_stm32l0xx.c" %src_dir%"\lib\"

mkdir %src_dir%"\hal\"
copy %lora_dir%"\Drivers\STM32L0xx_HAL_Driver\Src" %src_dir%"\hal\"
copy %lora_dir%"\Drivers\STM32L0xx_HAL_Driver\Inc" %src_dir%"\hal\"
copy %lora_dir%"\Drivers\CMSIS\Include" %src_dir%"\hal\"
mkdir %src_dir%"\hal\legacy\"
copy %lora_dir%"\Drivers\STM32L0xx_HAL_Driver\Inc\Legacy" %src_dir%"\hal\legacy\"
copy %lora_dir%"\Drivers\CMSIS\Device\ST\STM32L0xx\Include" %src_dir%"\hal\"

copy %lora_dir%"\Projects\B-L072Z-LRWAN1\Applications\LoRa\End_Node\MDK-ARM\startup_stm32l072xx.s" %src_dir%
copy %lora_dir%"\Projects\B-L072Z-LRWAN1\Applications\LoRa\End_Node\Core\inc\" %src_dir%
copy %lora_dir%"\Projects\B-L072Z-LRWAN1\Applications\LoRa\End_Node\Core\src\" %src_dir%

copy %lora_dir%"\Middlewares\Third_Party\LoRaWAN\Core" %src_dir%"\lib\"

copy %lora_dir%"\Middlewares\Third_Party\LoRaWAN\Mac" %src_dir%"\lib\"
mkdir %src_dir%"\lib\region\"
copy %lora_dir%"\Middlewares\Third_Party\LoRaWAN\Mac\region" %src_dir%"\lib\region\"

copy %lora_dir%"\Middlewares\Third_Party\LoRaWAN\Utilities" %src_dir%"\lib\"

copy %lora_dir%"\Middlewares\Third_Party\LoRaWAN\Crypto" %src_dir%"\lib\"
copy %lora_dir%"\Middlewares\Third_Party\LoRaWAN\Phy" %src_dir%"\lib\"



copy %lora_dir%"\Projects\B-L072Z-LRWAN1\Applications\LoRa\End_Node\LoRaWAN\App\inc\" %src_dir%
copy %lora_dir%"\Projects\B-L072Z-LRWAN1\Applications\LoRa\End_Node\LoRaWAN\App\src\" %src_dir%
