################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/procesoCPU.c 

OBJS += \
./src/procesoCPU.o 

C_DEPS += \
./src/procesoCPU.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -D"LD_LIBRARY_PATH=/home/utnso/workspace/home/utnso/tp-2014-1c-bar-c-lona/pruebaShared/Debug" -I"/home/utnso/tp-2014-1c-bar-c-lona/pruebaShared" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


