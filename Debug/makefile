################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/bsp/nano_stubs/subdir.mk
-include src/bsp/generate/src/subdir.mk
-include src/bsp/env/subdir.mk
-include src/bsp/drivers/Uart_TS_TTA8M1I1P0/src/subdir.mk
-include src/bsp/drivers/Port_TS_TTA8M1I1P0/src/subdir.mk
-include src/bsp/drivers/Platform_TS_TTA8M1I1P0/src/subdir.mk
-include src/bsp/drivers/Mcu_TS_TTA8M1I1P0/src/subdir.mk
-include src/bsp/drivers/I2c_TS_TTA8M1I1P0/src/subdir.mk
-include src/bsp/drivers/Gtm_TS_TTA8M1I1P0/src/subdir.mk
-include src/bsp/drivers/Gpt_TS_TTA8M1I1P0/src/subdir.mk
-include src/bsp/drivers/Dma_TS_TTA8M1I1P0/src/subdir.mk
-include src/bsp/drivers/Dio_TS_TTA8M1I1P0/src/subdir.mk
-include src/bsp/drivers/Can_TS_TTA8M1I1P0/src/subdir.mk
-include src/bsp/drivers/Base_TS_TTA8M1I1P0/src/subdir.mk
-include src/bsp/drivers/Adc_TS_TTA8M1I1P0/src/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := TT_Chassis_OK6_6
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
TT_Chassis_OK6_6.hex \

SECONDARY_SIZE += \
TT_Chassis_OK6_6.siz \


# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: TT_Chassis_OK6_6.elf secondary-outputs

# Tool invocations
TT_Chassis_OK6_6.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU Arm Cross C Linker'
	clang -mcpu=cortex-m7 -march=armv7e-m -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-d16 --target=arm-none-eabi -Os -ffunction-sections -fdata-sections -fno-common -funsigned-char -fomit-frame-pointer -fno-short-enums -fstack-usage -pedantic -Wunused -Wall -Wextra  -g3 -T "D:\software\TTstudio\ThinkTechStudio-workspace\TT_Chassis_OK6_6\src\bsp\env\linker_flash_m7.ld" -Xlinker --gc-sections -Wl,-Map,"TT_Chassis_OK6_6.map" -o "TT_Chassis_OK6_6.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TT_Chassis_OK6_6.hex: TT_Chassis_OK6_6.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU Arm Cross Create Flash Image'
	llvm-objcopy -O ihex "TT_Chassis_OK6_6.elf"  "TT_Chassis_OK6_6.hex"
	@echo 'Finished building: $@'
	@echo ' '

TT_Chassis_OK6_6.siz: TT_Chassis_OK6_6.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU Arm Cross Print Size'
	llvm-size --format=berkeley "TT_Chassis_OK6_6.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) TT_Chassis_OK6_6.elf
	-@echo ' '

post-build:
	-llvm-objdump -D "TT_Chassis_OK6_6.elf" > "TT_Chassis_OK6_6.dis";llvm-objcopy -O binary "TT_Chassis_OK6_6.elf" "TT_Chassis_OK6_6.bin"
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
