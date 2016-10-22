################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/main.c" \
"../Sources/motor.c" \
"../Sources/seguidor.c" \
"../Sources/timers.c" \

C_SRCS += \
../Sources/main.c \
../Sources/motor.c \
../Sources/seguidor.c \
../Sources/timers.c \

OBJS += \
./Sources/main_c.obj \
./Sources/motor_c.obj \
./Sources/seguidor_c.obj \
./Sources/timers_c.obj \

OBJS_QUOTED += \
"./Sources/main_c.obj" \
"./Sources/motor_c.obj" \
"./Sources/seguidor_c.obj" \
"./Sources/timers_c.obj" \

C_DEPS += \
./Sources/main_c.d \
./Sources/motor_c.d \
./Sources/seguidor_c.d \
./Sources/timers_c.d \

C_DEPS_QUOTED += \
"./Sources/main_c.d" \
"./Sources/motor_c.d" \
"./Sources/seguidor_c.d" \
"./Sources/timers_c.d" \

OBJS_OS_FORMAT += \
./Sources/main_c.obj \
./Sources/motor_c.obj \
./Sources/seguidor_c.obj \
./Sources/timers_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/motor_c.obj: ../Sources/motor.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/motor.args" -ObjN="Sources/motor_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/seguidor_c.obj: ../Sources/seguidor.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/seguidor.args" -ObjN="Sources/seguidor_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/timers_c.obj: ../Sources/timers.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/timers.args" -ObjN="Sources/timers_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


