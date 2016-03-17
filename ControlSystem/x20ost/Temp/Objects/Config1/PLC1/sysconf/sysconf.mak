$(AS_CPU_PATH)/sysconf.br: \
	$(AS_PROJECT_PATH)/physical/$(AS_CONFIGURATION)/$(AS_PLC)/sysconf.br \
	$(AS_PROJECT_PATH)/physical/$(AS_CONFIGURATION)/hardware.hc 
	@$(AS_BIN_PATH)/BR.AS.ConfigurationBuilder.exe "$(AS_PROJECT_PATH)/Physical/$(AS_CONFIGURATION)/$(AS_PLC)/sysconf.br" "$(AS_PROJECT_PATH)/Physical/$(AS_CONFIGURATION)/Hardware.hc"  -sysconf -S PLC1 -o "$(AS_CPU_PATH)/sysconf.br" -T SGC -B V2.00 -P "$(AS_PROJECT_PATH)" -s PLC1 -secret "$(AS_PROJECT_PATH)_br.as.configurationbuilder.exe"

-include $(AS_CPU_PATH)/Force.mak 
