################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bsp/env/exceptions_m7.c \
../src/bsp/env/startup_init_data_m7.c \
../src/bsp/env/system_m7.c 

S_UPPER_SRCS += \
../src/bsp/env/startup_m7.S \
../src/bsp/env/vector_table_m7.S 

OBJS += \
./src/bsp/env/exceptions_m7.o \
./src/bsp/env/startup_init_data_m7.o \
./src/bsp/env/startup_m7.o \
./src/bsp/env/system_m7.o \
./src/bsp/env/vector_table_m7.o 

S_UPPER_DEPS += \
./src/bsp/env/startup_m7.d \
./src/bsp/env/vector_table_m7.d 

C_DEPS += \
./src/bsp/env/exceptions_m7.d \
./src/bsp/env/startup_init_data_m7.d \
./src/bsp/env/system_m7.d 


# Each subdirectory must supply rules for building sources it contributes
src/bsp/env/%.o: ../src/bsp/env/%.c src/bsp/env/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: LLVMEmbeddedToolchainForArm'
	clang -mcpu=cortex-m7 -march=armv7e-m -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-d16 --target=arm-none-eabi -Os -ffunction-sections -fdata-sections -fno-common -funsigned-char -fomit-frame-pointer -fno-short-enums -fstack-usage -pedantic -Wunused -Wall -Wextra  -g3 -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Adc_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Base_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Base_TS_TTA8M1I1P0\header" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Base_TS_TTA8M1I1P0\interface\memmap_inc" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Can_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Dio_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Dma_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Gpt_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Gtm_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\I2c_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Mcu_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Platform_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Uart_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\drivers\Port_TS_TTA8M1I1P0\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\env" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\generate" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\generate\include" -I"D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\nano_stubs" -std=c99 -D_LLVM_C_ALIOTHXX_ -DUART1_PRINTF -DMPU_ENABLE -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bsp/env/%.o: ../src/bsp/env/%.S src/bsp/env/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross Assembler'
	clang -mcpu=cortex-m7 -march=armv7e-m -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-d16 --target=arm-none-eabi -Os -ffunction-sections -fdata-sections -fno-common -funsigned-char -fomit-frame-pointer -fno-short-enums -fstack-usage -pedantic -Wunused -Wall -Wextra  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


