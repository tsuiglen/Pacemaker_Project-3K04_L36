###########################################################################
## Makefile generated for Simulink model 'led_model'. 
## 
## Makefile     : led_model.mk
## Generated on : Thu Oct 29 14:28:14 2020
## MATLAB Coder version: 5.0 (R2020a)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/led_model.elf
## Product type : executable
## Build type   : Top-Level Standalone Executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file

PRODUCT_NAME              = led_model
MAKEFILE                  = led_model.mk
MATLAB_ROOT               = /Users/atrio/Desktop/Matlab/MATLAB_R2020a.app
MATLAB_BIN                = /Users/atrio/Desktop/Matlab/MATLAB_R2020a.app/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/maci64
MASTER_ANCHOR_DIR         = 
START_DIR                 = /Users/atrio/Desktop/3K04\ Project/3K04_L36
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
COMPILER_COMMAND_FILE     = led_model_comp.rsp
CMD_FILE                  = led_model.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU Tools for ARM Embedded Processors
# Supported Version(s):    
# ToolchainInfo Version:   2020a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# TARGET_LOAD_CMD_ARGS
# TARGET_LOAD_CMD
# MW_GNU_ARM_TOOLS_PATH
# FDATASECTIONS_FLG

#-----------
# MACROS
#-----------

LIBGCC                = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-libgcc-file-name}
LIBC                  = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libc.a}
LIBM                  = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libm.a}
PRODUCT_BIN           = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).bin
PRODUCT_HEX           = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
CPFLAGS               = -O binary

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: GNU ARM Assembler
AS_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AS = "$(AS_PATH)/arm-none-eabi-gcc"

# C Compiler: GNU ARM C Compiler
CC_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CC = "$(CC_PATH)/arm-none-eabi-gcc"

# Linker: GNU ARM Linker
LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
LD = "$(LD_PATH)/arm-none-eabi-g++"

# C++ Compiler: GNU ARM C++ Compiler
CPP_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP = "$(CPP_PATH)/arm-none-eabi-g++"

# C++ Linker: GNU ARM C++ Linker
CPP_LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP_LD = "$(CPP_LD_PATH)/arm-none-eabi-g++"

# Archiver: GNU ARM Archiver
AR_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AR = "$(AR_PATH)/arm-none-eabi-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Binary Converter: Binary Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = "$(OBJCOPYPATH)/arm-none-eabi-objcopy"

# Hex Converter: Hex Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = "$(OBJCOPYPATH)/arm-none-eabi-objcopy"

# Executable Size: Executable Size
EXESIZEPATH = $(MW_GNU_ARM_TOOLS_PATH)
EXESIZE = "$(EXESIZEPATH)/arm-none-eabi-size"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/maci64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /f/q
ECHO                = @echo
MV                  = @mv
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
ASFLAGS              = -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = $(FDATASECTIONS_FLG) \
                       -Wall \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -c \
                       -O0
CPPFLAGS             = -std=gnu++14 \
                       -fno-rtti \
                       -fno-exceptions \
                       $(FDATASECTIONS_FLG) \
                       -Wall \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -c \
                       -O0
CPP_LDFLAGS          = -Wl,--gc-sections \
                       -Wl,-Map="$(PRODUCT_NAME).map"
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       =
EXESIZE_FLAGS        = $(PRODUCT)
EXECUTE_FLAGS        =
OBJCOPYFLAGS_HEX     = -O ihex $(PRODUCT) $(PRODUCT_HEX)
LDFLAGS              = -Wl,--gc-sections \
                       -Wl,-Map="$(PRODUCT_NAME).map"
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/led_model.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DMODEL=led_model -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DNULL=0 -DEXIT_FAILURE=1 -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DTARGET_K64F -DTARGET_Freescale -DTOOLCHAIN_GCC_ARM -DTOOLCHAIN_GCC -DTARGET_K64F -DTARGET_M4 -DTARGET_CORTEX_M -DTARGET_Freescale -DTARGET_KPSDK_MCUS -DTARGET_KPSDK_CODE -DTARGET_MCU_K64F -DTARGET_FRDM -DTOOLCHAIN_GCC_ARM -DTOOLCHAIN_GCC -D__CORTEX_M4 -DARM_MATH_CM4 -D__FPU_PRESENT=1 -DCPU_MK64FN1M0VMD12 -DFRDM_K64F120M -DFREEDOM -D__STACK_SIZE=0x2000 -D__HEAP_SIZE=0x2000 -DCLOCK_SETUP -D__FPU_USED=1 -DUSE_RTX -DOS_ROBIN=0 -DOS_TIMERS=1 -DOS_TIMERPRIO=6 -DOS_TIMERSTKSZ=200 -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DOS_CLOCK=120000000 -DOS_TICK=1000 -DMW_BASERATEMULTIPLIER=1 -DOS_TASKCNT=2 -DOS_STKSIZE=1088 -DOS_MAINSTKSIZE=512
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0
DEFINES_SKIPFORSIL = -DNULL=0 -DEXIT_FAILURE=1 -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DTARGET_K64F -DTARGET_Freescale -DTOOLCHAIN_GCC_ARM -DTOOLCHAIN_GCC -DTARGET_K64F -DTARGET_M4 -DTARGET_CORTEX_M -DTARGET_Freescale -DTARGET_KPSDK_MCUS -DTARGET_KPSDK_CODE -DTARGET_MCU_K64F -DTARGET_FRDM -DTOOLCHAIN_GCC_ARM -DTOOLCHAIN_GCC -D__CORTEX_M4 -DARM_MATH_CM4 -D__FPU_PRESENT=1 -DCPU_MK64FN1M0VMD12 -DFRDM_K64F120M -DFREEDOM -D__STACK_SIZE=0x2000 -D__HEAP_SIZE=0x2000 -DCLOCK_SETUP -D__FPU_USED=1 -DUSE_RTX -DOS_ROBIN=0 -DOS_TIMERS=1 -DOS_TIMERPRIO=6 -DOS_TIMERSTKSZ=200 -DSTACK_SIZE=64 -DOS_CLOCK=120000000 -DOS_TICK=1000 -DMW_BASERATEMULTIPLIER=1 -DOS_TASKCNT=2 -DOS_STKSIZE=1088 -DOS_MAINSTKSIZE=512
DEFINES_STANDARD = -DMODEL=led_model -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/MW_digitalIO.c /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/mw_sdk_interface.c $(START_DIR)/led_model_ert_rtw/led_model.c $(START_DIR)/led_model_ert_rtw/led_model_data.c /Users/atrio/Desktop/Matlab/KSDK_1.2.0/platform/devices/startup.c /Users/atrio/Desktop/Matlab/KSDK_1.2.0/platform/devices/MK64F12/startup/system_MK64F12.c /Users/atrio/Desktop/Matlab/KSDK_1.2.0/platform/devices/MK64F12/startup/gcc/startup_MK64F12.S /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/board.c /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/hardware_init.c /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/pin_mux.c /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/fsl_misc_utilities.c /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/fsl_edma_irq.c /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/fsl_uart_irq.c /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/irq_stub.c /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/sbrk.c /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/armcortexmbase/cmsis_rtos_rtx/src/cmsis_rtos_init.c /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/3P.instrset/cmsis.instrset/CMSIS/RTOS/RTX/Templates/RTX_Conf_CM.c /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/armcortexmbase/cmsis_rtos_rtx/src/mw_thread.c /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/armcortexmbase/cmsis_rtos_rtx/src/mw_semaphore.c /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/armcortexmbase/cmsis_rtos_rtx/src/mw_timer.c /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/armcortexmbase/cmsis_rtos_rtx/src/mw_signal.c

MAIN_SRC = $(START_DIR)/led_model_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = MW_digitalIO.o mw_sdk_interface.o led_model.o led_model_data.o startup.o system_MK64F12.o startup_MK64F12.o board.o hardware_init.o pin_mux.o fsl_misc_utilities.o fsl_edma_irq.o fsl_uart_irq.o irq_stub.o sbrk.o cmsis_rtos_init.o RTX_Conf_CM.o mw_thread.o mw_semaphore.o mw_timer.o mw_signal.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/3P.instrset/cmsis.instrset/CMSIS/Lib/GCC/libarm_cortexM4lf_math.a /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/3P.instrset/cmsis.instrset/CMSIS/RTOS/RTX/LIB/GCC/libRTX_CM4.a /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/ksdk_armgcc_lib/bm/libksdk_platform.a

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -fexceptions -fno-common -fmessage-length=0 -ffunction-sections -fdata-sections -Wall -ffreestanding -fno-builtin -mapcs -std=gnu99
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -fexceptions -fno-common -fmessage-length=0 -ffunction-sections -fdata-sections -Wall -ffreestanding -fno-builtin -mapcs -std=gnu99
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard --specs=nosys.specs -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -L"/Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src" -T "MK64FN1M0xxx12_flash_1.ld" -g -Xlinker --gc-sections -Wl,-Map=$(PRODUCT_NAME).map

CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard --specs=nosys.specs -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -L"/Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src" -T "MK64FN1M0xxx12_flash_1.ld" -g -Xlinker --gc-sections -Wl,-Map=$(PRODUCT_NAME).map

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard --specs=nosys.specs -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -L"/Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src" -T "MK64FN1M0xxx12_flash_1.ld" -g -Xlinker --gc-sections -Wl,-Map=$(PRODUCT_NAME).map

LDFLAGS += $(LDFLAGS_SKIPFORSIL)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard --specs=nosys.specs -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -L"/Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src" -T "MK64FN1M0xxx12_flash_1.ld" -g -Xlinker --gc-sections -Wl,-Map=$(PRODUCT_NAME).map

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


ALL_DEPS:=$(patsubst %.o,%.dep,$(ALL_OBJS))
all:

ifndef DISABLE_GCC_FUNCTION_DATA_SECTIONS
FDATASECTIONS_FLG := -ffunction-sections -fdata-sections
endif



-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include ../../codertarget_assembly_flags.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)
	@echo "### Invoking postbuild tool "Binary Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_BIN)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "Hex Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_HEX)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "Executable Size" ..."
	$(EXESIZE) $(EXESIZE_FLAGS)
	@echo "### Done invoking postbuild tool."


download : postbuild


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/led_model_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/led_model_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/led_model_ert_rtw/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/led_model_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/led_model_ert_rtw/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/led_model_ert_rtw/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/led_model_ert_rtw/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_digitalIO.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/MW_digitalIO.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mw_sdk_interface.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/mw_sdk_interface.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ert_main.o : $(START_DIR)/led_model_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


led_model.o : $(START_DIR)/led_model_ert_rtw/led_model.c
	$(CC) $(CFLAGS) -o "$@" "$<"


led_model_data.o : $(START_DIR)/led_model_ert_rtw/led_model_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


startup.o : /Users/atrio/Desktop/Matlab/KSDK_1.2.0/platform/devices/startup.c
	$(CC) $(CFLAGS) -o "$@" "$<"


system_MK64F12.o : /Users/atrio/Desktop/Matlab/KSDK_1.2.0/platform/devices/MK64F12/startup/system_MK64F12.c
	$(CC) $(CFLAGS) -o "$@" "$<"


startup_MK64F12.o : /Users/atrio/Desktop/Matlab/KSDK_1.2.0/platform/devices/MK64F12/startup/gcc/startup_MK64F12.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


board.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/board.c
	$(CC) $(CFLAGS) -o "$@" "$<"


hardware_init.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/hardware_init.c
	$(CC) $(CFLAGS) -o "$@" "$<"


pin_mux.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/pin_mux.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fsl_misc_utilities.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/fsl_misc_utilities.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fsl_edma_irq.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/fsl_edma_irq.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fsl_uart_irq.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/fsl_uart_irq.c
	$(CC) $(CFLAGS) -o "$@" "$<"


irq_stub.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/irq_stub.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sbrk.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/freedomk64f/src/sbrk.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cmsis_rtos_init.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/armcortexmbase/cmsis_rtos_rtx/src/cmsis_rtos_init.c
	$(CC) $(CFLAGS) -o "$@" "$<"


RTX_Conf_CM.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/3P.instrset/cmsis.instrset/CMSIS/RTOS/RTX/Templates/RTX_Conf_CM.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mw_thread.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/armcortexmbase/cmsis_rtos_rtx/src/mw_thread.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mw_semaphore.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/armcortexmbase/cmsis_rtos_rtx/src/mw_semaphore.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mw_timer.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/armcortexmbase/cmsis_rtos_rtx/src/mw_timer.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mw_signal.o : /Users/atrio/Documents/MATLAB/SupportPackages/R2020a_1/toolbox/target/supportpackages/armcortexmbase/cmsis_rtos_rtx/src/mw_signal.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_BIN = $(OBJCOPYFLAGS_BIN)"
	@echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	@echo "### EXESIZE_FLAGS = $(EXESIZE_FLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(RM) *.dep
	$(ECHO) "### Deleted all derived files."


