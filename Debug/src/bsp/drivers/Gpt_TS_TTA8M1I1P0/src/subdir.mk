################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bsp/drivers/Gpt_TS_TTA8M1I1P0/src/Gpt.c \
../src/bsp/drivers/Gpt_TS_TTA8M1I1P0/src/Gpt_Hw.c 

OBJS += \
./src/bsp/drivers/Gpt_TS_TTA8M1I1P0/src/Gpt.o \
./src/bsp/drivers/Gpt_TS_TTA8M1I1P0/src/Gpt_Hw.o 

C_DEPS += \
./src/bsp/drivers/Gpt_TS_TTA8M1I1P0/src/Gpt.d \
./src/bsp/drivers/Gpt_TS_TTA8M1I1P0/src/Gpt_Hw.d 


# Each subdirectory must supply rules for building sources it contributes
src/bsp/drivers/Gpt_TS_TTA8M1I1P0/src/%.o: ../src/bsp/drivers/Gpt_TS_TTA8M1I1P0/src/%.c src/bsp/drivers/Gpt_TS_TTA8M1I1P0/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: LLVMEmbeddedToolchainForArm'
	clang -mcpu=cortex-m7 -march=armv7e-m -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-d16 --target=arm-none-eabi -Os -ffunction-sections -fdata-sections -fno-common -funsigned-char -fomit-frame-pointer -fno-short-enums -fstack-usage -pedantic -Wunused -Wall -Wextra  -g3 -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Adc_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Base_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Base_TS_TTA8M1I1P0\header" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Base_TS_TTA8M1I1P0\interface\memmap_inc" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Can_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Dio_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Dma_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Gpt_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Gtm_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\I2c_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Mcu_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Platform_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Uart_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Port_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\env" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\generate" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\generate\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\nano_stubs" -std=c99 -D_LLVM_C_ALIOTHXX_ -DUART1_PRINTF -DMPU_ENABLE -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


