################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DSP/SupportFunctions/arm_copy_f32.c \
../Drivers/DSP/SupportFunctions/arm_copy_q15.c \
../Drivers/DSP/SupportFunctions/arm_copy_q31.c \
../Drivers/DSP/SupportFunctions/arm_copy_q7.c \
../Drivers/DSP/SupportFunctions/arm_fill_f32.c \
../Drivers/DSP/SupportFunctions/arm_fill_q15.c \
../Drivers/DSP/SupportFunctions/arm_fill_q31.c \
../Drivers/DSP/SupportFunctions/arm_fill_q7.c \
../Drivers/DSP/SupportFunctions/arm_float_to_q15.c \
../Drivers/DSP/SupportFunctions/arm_float_to_q31.c \
../Drivers/DSP/SupportFunctions/arm_float_to_q7.c \
../Drivers/DSP/SupportFunctions/arm_q15_to_float.c \
../Drivers/DSP/SupportFunctions/arm_q15_to_q31.c \
../Drivers/DSP/SupportFunctions/arm_q15_to_q7.c \
../Drivers/DSP/SupportFunctions/arm_q31_to_float.c \
../Drivers/DSP/SupportFunctions/arm_q31_to_q15.c \
../Drivers/DSP/SupportFunctions/arm_q31_to_q7.c \
../Drivers/DSP/SupportFunctions/arm_q7_to_float.c \
../Drivers/DSP/SupportFunctions/arm_q7_to_q15.c \
../Drivers/DSP/SupportFunctions/arm_q7_to_q31.c 

OBJS += \
./Drivers/DSP/SupportFunctions/arm_copy_f32.o \
./Drivers/DSP/SupportFunctions/arm_copy_q15.o \
./Drivers/DSP/SupportFunctions/arm_copy_q31.o \
./Drivers/DSP/SupportFunctions/arm_copy_q7.o \
./Drivers/DSP/SupportFunctions/arm_fill_f32.o \
./Drivers/DSP/SupportFunctions/arm_fill_q15.o \
./Drivers/DSP/SupportFunctions/arm_fill_q31.o \
./Drivers/DSP/SupportFunctions/arm_fill_q7.o \
./Drivers/DSP/SupportFunctions/arm_float_to_q15.o \
./Drivers/DSP/SupportFunctions/arm_float_to_q31.o \
./Drivers/DSP/SupportFunctions/arm_float_to_q7.o \
./Drivers/DSP/SupportFunctions/arm_q15_to_float.o \
./Drivers/DSP/SupportFunctions/arm_q15_to_q31.o \
./Drivers/DSP/SupportFunctions/arm_q15_to_q7.o \
./Drivers/DSP/SupportFunctions/arm_q31_to_float.o \
./Drivers/DSP/SupportFunctions/arm_q31_to_q15.o \
./Drivers/DSP/SupportFunctions/arm_q31_to_q7.o \
./Drivers/DSP/SupportFunctions/arm_q7_to_float.o \
./Drivers/DSP/SupportFunctions/arm_q7_to_q15.o \
./Drivers/DSP/SupportFunctions/arm_q7_to_q31.o 

C_DEPS += \
./Drivers/DSP/SupportFunctions/arm_copy_f32.d \
./Drivers/DSP/SupportFunctions/arm_copy_q15.d \
./Drivers/DSP/SupportFunctions/arm_copy_q31.d \
./Drivers/DSP/SupportFunctions/arm_copy_q7.d \
./Drivers/DSP/SupportFunctions/arm_fill_f32.d \
./Drivers/DSP/SupportFunctions/arm_fill_q15.d \
./Drivers/DSP/SupportFunctions/arm_fill_q31.d \
./Drivers/DSP/SupportFunctions/arm_fill_q7.d \
./Drivers/DSP/SupportFunctions/arm_float_to_q15.d \
./Drivers/DSP/SupportFunctions/arm_float_to_q31.d \
./Drivers/DSP/SupportFunctions/arm_float_to_q7.d \
./Drivers/DSP/SupportFunctions/arm_q15_to_float.d \
./Drivers/DSP/SupportFunctions/arm_q15_to_q31.d \
./Drivers/DSP/SupportFunctions/arm_q15_to_q7.d \
./Drivers/DSP/SupportFunctions/arm_q31_to_float.d \
./Drivers/DSP/SupportFunctions/arm_q31_to_q15.d \
./Drivers/DSP/SupportFunctions/arm_q31_to_q7.d \
./Drivers/DSP/SupportFunctions/arm_q7_to_float.d \
./Drivers/DSP/SupportFunctions/arm_q7_to_q15.d \
./Drivers/DSP/SupportFunctions/arm_q7_to_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/DSP/SupportFunctions/arm_copy_f32.o: ../Drivers/DSP/SupportFunctions/arm_copy_f32.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_copy_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_copy_q15.o: ../Drivers/DSP/SupportFunctions/arm_copy_q15.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_copy_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_copy_q31.o: ../Drivers/DSP/SupportFunctions/arm_copy_q31.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_copy_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_copy_q7.o: ../Drivers/DSP/SupportFunctions/arm_copy_q7.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_copy_q7.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_fill_f32.o: ../Drivers/DSP/SupportFunctions/arm_fill_f32.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_fill_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_fill_q15.o: ../Drivers/DSP/SupportFunctions/arm_fill_q15.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_fill_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_fill_q31.o: ../Drivers/DSP/SupportFunctions/arm_fill_q31.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_fill_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_fill_q7.o: ../Drivers/DSP/SupportFunctions/arm_fill_q7.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_fill_q7.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_float_to_q15.o: ../Drivers/DSP/SupportFunctions/arm_float_to_q15.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_float_to_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_float_to_q31.o: ../Drivers/DSP/SupportFunctions/arm_float_to_q31.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_float_to_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_float_to_q7.o: ../Drivers/DSP/SupportFunctions/arm_float_to_q7.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_float_to_q7.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_q15_to_float.o: ../Drivers/DSP/SupportFunctions/arm_q15_to_float.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_q15_to_float.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_q15_to_q31.o: ../Drivers/DSP/SupportFunctions/arm_q15_to_q31.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_q15_to_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_q15_to_q7.o: ../Drivers/DSP/SupportFunctions/arm_q15_to_q7.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_q15_to_q7.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_q31_to_float.o: ../Drivers/DSP/SupportFunctions/arm_q31_to_float.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_q31_to_float.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_q31_to_q15.o: ../Drivers/DSP/SupportFunctions/arm_q31_to_q15.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_q31_to_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_q31_to_q7.o: ../Drivers/DSP/SupportFunctions/arm_q31_to_q7.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_q31_to_q7.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_q7_to_float.o: ../Drivers/DSP/SupportFunctions/arm_q7_to_float.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_q7_to_float.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_q7_to_q15.o: ../Drivers/DSP/SupportFunctions/arm_q7_to_q15.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_q7_to_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/SupportFunctions/arm_q7_to_q31.o: ../Drivers/DSP/SupportFunctions/arm_q7_to_q31.c Drivers/DSP/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/SupportFunctions/arm_q7_to_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

