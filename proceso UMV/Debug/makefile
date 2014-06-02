################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: UMV

dependents:
	-cd /home/utnso/workspace/tp-2014-1c-bar-c-lona/pruebaShared/Debug && $(MAKE) clean all
	-cd /home/utnso/workspace/tp-2014-1c-bar-c-lona/proceso\ UMV/Release && $(MAKE) clean all

# Tool invocations
UMV: $(OBJS) $(USER_OBJS) /home/utnso/workspace/tp-2014-1c-bar-c-lona/pruebaShared/Debug/libpruebaShared.so /home/utnso/workspace/tp-2014-1c-bar-c-lona/proceso\ UMV/Release/UMV
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -L"/home/utnso/workspace/tp-2014-1c-bar-c-lona/pruebaShared/Debug" -o "UMV" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) UMV
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
/home/utnso/workspace/tp-2014-1c-bar-c-lona/pruebaShared/Debug/libpruebaShared.so:
/home/utnso/workspace/tp-2014-1c-bar-c-lona/proceso\ UMV/Release/UMV:

-include ../makefile.targets
