################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_f32.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_q15.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_q31.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_f32.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_q15.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_q31.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_f32.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_q15.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_q31.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_f32.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_q15.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_q31.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_f32.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_q15.c \
../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_q31.c 

OBJS += \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_f32.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_q15.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_q31.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_f32.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_q15.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_q31.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_f32.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_q15.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_q31.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_f32.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_q15.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_q31.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_f32.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_q15.o \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_q31.o 

C_DEPS += \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_f32.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_q15.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_q31.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_f32.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_q15.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_q31.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_f32.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_q15.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_q31.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_f32.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_q15.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_q31.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_f32.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_q15.d \
./Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_f32.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_f32.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_q15.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_q15.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_q31.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_q31.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_conj_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_f32.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_f32.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_q15.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_q15.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_q31.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_q31.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_dot_prod_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_f32.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_f32.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_q15.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_q15.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_q31.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_q31.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_f32.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_f32.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_q15.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_q15.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_q31.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_q31.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_mag_squared_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_f32.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_f32.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_q15.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_q15.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_q31.o: ../Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_q31.c Drivers/DSP/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/ComplexMathFunctions/arm_cmplx_mult_real_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

