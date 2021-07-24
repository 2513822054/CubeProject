################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DSP/MatrixFunctions/arm_mat_add_f32.c \
../Drivers/DSP/MatrixFunctions/arm_mat_add_q15.c \
../Drivers/DSP/MatrixFunctions/arm_mat_add_q31.c \
../Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_f32.c \
../Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_q15.c \
../Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_q31.c \
../Drivers/DSP/MatrixFunctions/arm_mat_init_f32.c \
../Drivers/DSP/MatrixFunctions/arm_mat_init_q15.c \
../Drivers/DSP/MatrixFunctions/arm_mat_init_q31.c \
../Drivers/DSP/MatrixFunctions/arm_mat_inverse_f32.c \
../Drivers/DSP/MatrixFunctions/arm_mat_inverse_f64.c \
../Drivers/DSP/MatrixFunctions/arm_mat_mult_f32.c \
../Drivers/DSP/MatrixFunctions/arm_mat_mult_fast_q15.c \
../Drivers/DSP/MatrixFunctions/arm_mat_mult_fast_q31.c \
../Drivers/DSP/MatrixFunctions/arm_mat_mult_q15.c \
../Drivers/DSP/MatrixFunctions/arm_mat_mult_q31.c \
../Drivers/DSP/MatrixFunctions/arm_mat_scale_f32.c \
../Drivers/DSP/MatrixFunctions/arm_mat_scale_q15.c \
../Drivers/DSP/MatrixFunctions/arm_mat_scale_q31.c \
../Drivers/DSP/MatrixFunctions/arm_mat_sub_f32.c \
../Drivers/DSP/MatrixFunctions/arm_mat_sub_q15.c \
../Drivers/DSP/MatrixFunctions/arm_mat_sub_q31.c \
../Drivers/DSP/MatrixFunctions/arm_mat_trans_f32.c \
../Drivers/DSP/MatrixFunctions/arm_mat_trans_q15.c \
../Drivers/DSP/MatrixFunctions/arm_mat_trans_q31.c 

OBJS += \
./Drivers/DSP/MatrixFunctions/arm_mat_add_f32.o \
./Drivers/DSP/MatrixFunctions/arm_mat_add_q15.o \
./Drivers/DSP/MatrixFunctions/arm_mat_add_q31.o \
./Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_f32.o \
./Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_q15.o \
./Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_q31.o \
./Drivers/DSP/MatrixFunctions/arm_mat_init_f32.o \
./Drivers/DSP/MatrixFunctions/arm_mat_init_q15.o \
./Drivers/DSP/MatrixFunctions/arm_mat_init_q31.o \
./Drivers/DSP/MatrixFunctions/arm_mat_inverse_f32.o \
./Drivers/DSP/MatrixFunctions/arm_mat_inverse_f64.o \
./Drivers/DSP/MatrixFunctions/arm_mat_mult_f32.o \
./Drivers/DSP/MatrixFunctions/arm_mat_mult_fast_q15.o \
./Drivers/DSP/MatrixFunctions/arm_mat_mult_fast_q31.o \
./Drivers/DSP/MatrixFunctions/arm_mat_mult_q15.o \
./Drivers/DSP/MatrixFunctions/arm_mat_mult_q31.o \
./Drivers/DSP/MatrixFunctions/arm_mat_scale_f32.o \
./Drivers/DSP/MatrixFunctions/arm_mat_scale_q15.o \
./Drivers/DSP/MatrixFunctions/arm_mat_scale_q31.o \
./Drivers/DSP/MatrixFunctions/arm_mat_sub_f32.o \
./Drivers/DSP/MatrixFunctions/arm_mat_sub_q15.o \
./Drivers/DSP/MatrixFunctions/arm_mat_sub_q31.o \
./Drivers/DSP/MatrixFunctions/arm_mat_trans_f32.o \
./Drivers/DSP/MatrixFunctions/arm_mat_trans_q15.o \
./Drivers/DSP/MatrixFunctions/arm_mat_trans_q31.o 

C_DEPS += \
./Drivers/DSP/MatrixFunctions/arm_mat_add_f32.d \
./Drivers/DSP/MatrixFunctions/arm_mat_add_q15.d \
./Drivers/DSP/MatrixFunctions/arm_mat_add_q31.d \
./Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_f32.d \
./Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_q15.d \
./Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_q31.d \
./Drivers/DSP/MatrixFunctions/arm_mat_init_f32.d \
./Drivers/DSP/MatrixFunctions/arm_mat_init_q15.d \
./Drivers/DSP/MatrixFunctions/arm_mat_init_q31.d \
./Drivers/DSP/MatrixFunctions/arm_mat_inverse_f32.d \
./Drivers/DSP/MatrixFunctions/arm_mat_inverse_f64.d \
./Drivers/DSP/MatrixFunctions/arm_mat_mult_f32.d \
./Drivers/DSP/MatrixFunctions/arm_mat_mult_fast_q15.d \
./Drivers/DSP/MatrixFunctions/arm_mat_mult_fast_q31.d \
./Drivers/DSP/MatrixFunctions/arm_mat_mult_q15.d \
./Drivers/DSP/MatrixFunctions/arm_mat_mult_q31.d \
./Drivers/DSP/MatrixFunctions/arm_mat_scale_f32.d \
./Drivers/DSP/MatrixFunctions/arm_mat_scale_q15.d \
./Drivers/DSP/MatrixFunctions/arm_mat_scale_q31.d \
./Drivers/DSP/MatrixFunctions/arm_mat_sub_f32.d \
./Drivers/DSP/MatrixFunctions/arm_mat_sub_q15.d \
./Drivers/DSP/MatrixFunctions/arm_mat_sub_q31.d \
./Drivers/DSP/MatrixFunctions/arm_mat_trans_f32.d \
./Drivers/DSP/MatrixFunctions/arm_mat_trans_q15.d \
./Drivers/DSP/MatrixFunctions/arm_mat_trans_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/DSP/MatrixFunctions/arm_mat_add_f32.o: ../Drivers/DSP/MatrixFunctions/arm_mat_add_f32.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_add_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_add_q15.o: ../Drivers/DSP/MatrixFunctions/arm_mat_add_q15.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_add_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_add_q31.o: ../Drivers/DSP/MatrixFunctions/arm_mat_add_q31.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_add_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_f32.o: ../Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_f32.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_q15.o: ../Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_q15.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_q31.o: ../Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_q31.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_cmplx_mult_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_init_f32.o: ../Drivers/DSP/MatrixFunctions/arm_mat_init_f32.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_init_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_init_q15.o: ../Drivers/DSP/MatrixFunctions/arm_mat_init_q15.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_init_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_init_q31.o: ../Drivers/DSP/MatrixFunctions/arm_mat_init_q31.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_init_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_inverse_f32.o: ../Drivers/DSP/MatrixFunctions/arm_mat_inverse_f32.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_inverse_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_inverse_f64.o: ../Drivers/DSP/MatrixFunctions/arm_mat_inverse_f64.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_inverse_f64.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_mult_f32.o: ../Drivers/DSP/MatrixFunctions/arm_mat_mult_f32.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_mult_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_mult_fast_q15.o: ../Drivers/DSP/MatrixFunctions/arm_mat_mult_fast_q15.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_mult_fast_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_mult_fast_q31.o: ../Drivers/DSP/MatrixFunctions/arm_mat_mult_fast_q31.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_mult_fast_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_mult_q15.o: ../Drivers/DSP/MatrixFunctions/arm_mat_mult_q15.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_mult_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_mult_q31.o: ../Drivers/DSP/MatrixFunctions/arm_mat_mult_q31.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_mult_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_scale_f32.o: ../Drivers/DSP/MatrixFunctions/arm_mat_scale_f32.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_scale_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_scale_q15.o: ../Drivers/DSP/MatrixFunctions/arm_mat_scale_q15.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_scale_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_scale_q31.o: ../Drivers/DSP/MatrixFunctions/arm_mat_scale_q31.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_scale_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_sub_f32.o: ../Drivers/DSP/MatrixFunctions/arm_mat_sub_f32.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_sub_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_sub_q15.o: ../Drivers/DSP/MatrixFunctions/arm_mat_sub_q15.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_sub_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_sub_q31.o: ../Drivers/DSP/MatrixFunctions/arm_mat_sub_q31.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_sub_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_trans_f32.o: ../Drivers/DSP/MatrixFunctions/arm_mat_trans_f32.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_trans_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_trans_q15.o: ../Drivers/DSP/MatrixFunctions/arm_mat_trans_q15.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_trans_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/MatrixFunctions/arm_mat_trans_q31.o: ../Drivers/DSP/MatrixFunctions/arm_mat_trans_q31.c Drivers/DSP/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -D_TARGET_FPU_VFP '-D__FPU_PRESENT = 1U' -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/DSP/MatrixFunctions/arm_mat_trans_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

