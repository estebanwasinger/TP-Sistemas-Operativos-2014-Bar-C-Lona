################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bitarray.c \
../config.c \
../error.c \
../log.c \
../package.c \
../process.c \
../socket.c \
../string.c \
../temporal.c \
../txt.c 

OBJS += \
./bitarray.o \
./config.o \
./error.o \
./log.o \
./package.o \
./process.o \
./socket.o \
./string.o \
./temporal.o \
./txt.o 

C_DEPS += \
./bitarray.d \
./config.d \
./error.d \
./log.d \
./package.d \
./process.d \
./socket.d \
./string.d \
./temporal.d \
./txt.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


