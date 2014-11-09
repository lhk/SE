################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Assertion.cpp \
../src/Aufgabe1-2.cpp \
../src/PATM.cpp 

OBJS += \
./src/Assertion.o \
./src/Aufgabe1-2.o \
./src/PATM.o 

CPP_DEPS += \
./src/Assertion.d \
./src/Aufgabe1-2.d \
./src/PATM.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


