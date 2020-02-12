################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
tm4c123_firmware/mcal/nvic/%.obj: ../tm4c123_firmware/mcal/nvic/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="F:/SprintS/Weeks/week 11/Arm Projects/Sprints" --include_path="F:/SprintS/Weeks/week 11/Arm Projects/Sprints/tm4c123_firmware/utils/processor" --include_path="F:/SprintS/Weeks/week 11/Arm Projects/Sprints/tm4c123_firmware/utils" --include_path="F:/SprintS/Weeks/week 11/Arm Projects/Sprints/tm4c123_firmware/mcal/dio" --include_path="F:/SprintS/Weeks/week 11/Arm Projects/Sprints/tm4c123_firmware/mcal" --include_path="F:/SprintS/Weeks/week 11/Arm Projects/Sprints/tm4c123_firmware/config" --include_path="F:/SprintS/Weeks/week 11/Arm Projects/Sprints/tm4c123_firmware/mcal/nvic" --include_path="F:/SprintS/Weeks/week 11/Arm Projects/Sprints/tm4c123_firmware/mcal/PortDriver" --include_path="F:/SprintS/Weeks/week 11/Arm Projects/Sprints/tm4c123_firmware/mcal/SysCtr" --include_path="C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="tm4c123_firmware/mcal/nvic/$(basename $(<F)).d_raw" --obj_directory="tm4c123_firmware/mcal/nvic" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


