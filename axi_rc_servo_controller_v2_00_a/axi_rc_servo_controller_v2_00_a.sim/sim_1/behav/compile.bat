@echo off
rem  Vivado(TM)
rem  compile.bat: a Vivado-generated XSim simulation Script
rem  Copyright 1986-1999, 2001-2013 Xilinx, Inc. All Rights Reserved.

set PATH=%XILINX%\lib\%PLATFORM%;%XILINX%\bin\%PLATFORM%;C:/Xilinx/SDK/2013.4/bin/nt64;C:/Xilinx/Vivado/2013.4/ids_lite/EDK/bin/nt64;C:/Xilinx/Vivado/2013.4/ids_lite/EDK/lib/nt64;C:/Xilinx/Vivado/2013.4/ids_lite/ISE/bin/nt64;C:/Xilinx/Vivado/2013.4/ids_lite/ISE/lib/nt64;C:/Xilinx/Vivado/2013.4/bin;%PATH%
set XILINX_PLANAHEAD=C:/Xilinx/Vivado/2013.4

xelab -m64 --debug typical --relax -L axi_rc_servo_controller -L work -L secureip --snapshot axi_rc_servo_controller_testbench_behav --prj C:/custom_IPI_IP/MyProcessorIPLib/pcores/axi_rc_servo_controller_v2_00_a/axi_rc_servo_controller_v2_00_a.sim/sim_1/behav/axi_rc_servo_controller_testbench.prj   work.axi_rc_servo_controller_testbench
if errorlevel 1 (
   cmd /c exit /b %errorlevel%
)
