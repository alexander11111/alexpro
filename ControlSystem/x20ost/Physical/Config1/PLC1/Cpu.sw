<?xml version="1.0" encoding="utf-8"?>
<?AutomationStudio Version=3.0.71.10?>
<SwConfiguration CpuAddress="SL0" xmlns="http://br-automation.co.at/AS/SwConfiguration">
  <TaskClass Name="Cyclic#1" />
  <TaskClass Name="Cyclic#2" />
  <TaskClass Name="Cyclic#3" />
  <TaskClass Name="Cyclic#4">
    <Task Name="bnrmain" Source="bnrmain.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
  </TaskClass>
  <DataObjects>
    <DataObject Name="FlashModul" Source="" Memory="UserROM" Language="Binary" />
  </DataObjects>
  <NcDataObjects />
  <VcDataObjects />
  <Binaries>
    <BinaryObject Name="gcloader" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="iomap" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="arconfig" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="asfw" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="sysconf" Source="" Memory="UserROM" Language="Binary" />
  </Binaries>
  <Libraries>
    <LibraryObject Name="DataObj" Source="Libraries.DataObj.lby" Memory="UserROM" Language="binary" />
    <LibraryObject Name="DM_lib" Source="Libraries.DM_lib.lby" Memory="UserROM" Language="binary" />
    <LibraryObject Name="sys_lib" Source="Libraries.sys_lib.lby" Memory="UserROM" Language="binary" />
    <LibraryObject Name="runtime" Source="" Memory="UserROM" Language="Binary" />
    <LibraryObject Name="burtrap" Source="" Memory="UserROM" Language="Binary" />
    <LibraryObject Name="CAN_Lib" Source="Libraries.CAN_Lib.lby" Memory="UserROM" Language="binary" />
    <LibraryObject Name="AsTCP" Source="Libraries.AsTCP.lby" Memory="UserROM" Language="binary" />
    <LibraryObject Name="dvframe" Source="Libraries.dvframe.lby" Memory="UserROM" Language="binary" />
  </Libraries>
</SwConfiguration>