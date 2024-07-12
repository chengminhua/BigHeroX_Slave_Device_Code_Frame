################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bsp/generate/src/Adc_Drv_PBcfg.c \
../src/bsp/generate/src/Can_Drv_PBcfg.c \
../src/bsp/generate/src/Can_Hw_PBcfg.c \
../src/bsp/generate/src/Can_PBcfg.c \
../src/bsp/generate/src/Dio_Drv_PBcfg.c \
../src/bsp/generate/src/Dma_Drv_PBcfg.c \
../src/bsp/generate/src/Gpt_PBcfg.c \
../src/bsp/generate/src/Gtm_Drv_PBcfg.c \
../src/bsp/generate/src/I2c_Drv_PBcfg.c \
../src/bsp/generate/src/Mcu_PBcfg.c \
../src/bsp/generate/src/Platform_Drv_PBcfg.c \
../src/bsp/generate/src/Platform_IntCtrl_PBcfg.c \
../src/bsp/generate/src/Platform_Mpu_PBcfg.c \
../src/bsp/generate/src/Port_Drv_PBcfg.c \
../src/bsp/generate/src/Uart_Drv_PBcfg.c 

OBJS += \
./src/bsp/generate/src/Adc_Drv_PBcfg.o \
./src/bsp/generate/src/Can_Drv_PBcfg.o \
./src/bsp/generate/src/Can_Hw_PBcfg.o \
./src/bsp/generate/src/Can_PBcfg.o \
./src/bsp/generate/src/Dio_Drv_PBcfg.o \
./src/bsp/generate/src/Dma_Drv_PBcfg.o \
./src/bsp/generate/src/Gpt_PBcfg.o \
./src/bsp/generate/src/Gtm_Drv_PBcfg.o \
./src/bsp/generate/src/I2c_Drv_PBcfg.o \
./src/bsp/generate/src/Mcu_PBcfg.o \
./src/bsp/generate/src/Platform_Drv_PBcfg.o \
./src/bsp/generate/src/Platform_IntCtrl_PBcfg.o \
./src/bsp/generate/src/Platform_Mpu_PBcfg.o \
./src/bsp/generate/src/Port_Drv_PBcfg.o \
./src/bsp/generate/src/Uart_Drv_PBcfg.o 

C_DEPS += \
./src/bsp/generate/src/Adc_Drv_PBcfg.d \
./src/bsp/generate/src/Can_Drv_PBcfg.d \
./src/bsp/generate/src/Can_Hw_PBcfg.d \
./src/bsp/generate/src/Can_PBcfg.d \
./src/bsp/generate/src/Dio_Drv_PBcfg.d \
./src/bsp/generate/src/Dma_Drv_PBcfg.d \
./src/bsp/generate/src/Gpt_PBcfg.d \
./src/bsp/generate/src/Gtm_Drv_PBcfg.d \
./src/bsp/generate/src/I2c_Drv_PBcfg.d \
./src/bsp/generate/src/Mcu_PBcfg.d \
./src/bsp/generate/src/Platform_Drv_PBcfg.d \
./src/bsp/generate/src/Platform_IntCtrl_PBcfg.d \
./src/bsp/generate/src/Platform_Mpu_PBcfg.d \
./src/bsp/generate/src/Port_Drv_PBcfg.d \
./src/bsp/generate/src/Uart_Drv_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/bsp/generate/src/%.o: ../src/bsp/generate/src/%.c src/bsp/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: LLVMEmbeddedToolchainForArm'
	clang -mcpu=cortex-m7 -march=armv7e-m -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-d16 --target=arm-none-eabi -Os -ffunction-sections -fdata-sections -fno-common -funsigned-char -fomit-frame-pointer -fno-short-enums -fstack-usage -pedantic -Wunused -Wall -Wextra  -g3 -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Adc_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Base_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Base_TS_TTA8M1I1P0\header" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Base_TS_TTA8M1I1P0\interface\memmap_inc" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Can_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Dio_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Dma_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Gpt_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Gtm_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\I2c_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Mcu_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Platform_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Uart_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Port_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\env" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\generate" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\generate\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\nano_stubs" -std=c99 -D_LLVM_C_ALIOTHXX_ -DUART1_PRINTF -DMPU_ENABLE -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


