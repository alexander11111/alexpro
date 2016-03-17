SHELL = C:/Program\ Files/BrAutomation/AS30071/As/GnuInst/V2.95.3/bin/sh
CYGWIN=nontsec
export AS_COMPANY_NAME := b
export AS_USER_NAME := a1
export AS_PATH := C:/Program\ Files/BrAutomation/AS30071
export AS_BIN_PATH := C:/Program\ Files/BrAutomation/AS30071/Bin-en
export AS_PROJECT_PATH := D:/Vagez/x20ost
export AS_PROJECT_NAME := x20ost
export AS_SYSTEM_PATH := C:/Program\ Files/BrAutomation/As/System
export AS_TEMP_PATH := D:/Vagez/x20ost/Temp
export AS_CONFIGURATION := Config1
export AS_BINARIES_PATH := D:/Vagez/x20ost/Binaries
export AS_GNU_INST_PATH := C:/Program\ Files/BrAutomation/AS30071/As/GnuInst/V2.95.3
export AS_GNU_BIN_PATH := $(AS_GNU_INST_PATH)/bin
export AS_INSTALL_PATH := C:/Program\ Files/BrAutomation/AS30071
export WIN32_AS_PATH := C:\\Program Files\\BrAutomation\\AS30071
export WIN32_AS_BIN_PATH := C:\\Program Files\\BrAutomation\\AS30071\\Bin-en
export WIN32_AS_PROJECT_PATH := D:\\Vagez\\x20ost
export WIN32_AS_SYSTEM_PATH := C:\\Program Files\\BrAutomation\\As\\System
export WIN32_AS_TEMP_PATH := D:\\Vagez\\x20ost\\Temp
export WIN32_AS_BINARIES_PATH := D:\\Vagez\\x20ost\\Binaries
export WIN32_AS_GNU_INST_PATH := C:\\Program Files\\BrAutomation\\AS30071\\As\\GnuInst\\V2.95.3
export WIN32_AS_GNU_BIN_PATH := $(WIN32_AS_GNU_INST_PATH)\\bin
export WIN32_AS_INSTALL_PATH := C:\\Program Files\\BrAutomation\\AS30071

.suffixes:

ProjectMakeFile:

	@$(AS_BIN_PATH)/BR.AS.AnalyseProject.exe "$(AS_PROJECT_PATH)/x20ost.apj" -t "$(AS_TEMP_PATH)" -c "$(AS_CONFIGURATION)" -o "$(AS_BINARIES_PATH)" 

	@$(AS_GNU_BIN_PATH)/make.exe -r -f "D:/Vagez/x20ost/Temp/Objects/$(AS_CONFIGURATION)/PLC1/#cpu.mak" -k

