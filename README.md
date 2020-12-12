# checkpoint2
This Project is build by Microsoft Visual Studio 2017./n
To build this project:
1: open the my_battery.sln in MSV 2017
2: Set the configurations in the MSV as decribed below:
3: Add my_battery.c in source folder and my_battery.h in the header file and the property sheet to the property manager
4: Right click on the sln file,  build it
5: After build successful, click "Start without Debugging" in MSV
6: Then the data collection will start and you can press Ctrl+C to stop the process anytime
7: The input library created will be in the project folder.
Add the following props file to your project:
=============================================
	_xlsdk\src\build_variables\build_variables.props

Additional Include Directories(C/C++/General):
==============================================
	$(XLSDK_INCLUDES)

Preprocessor Definitions (C/C++/Preprocessor):
==============================================

	For ILs, use:
	=============
		$(COMMON_BUILD_SYMBOLS)
		$(INTEL_MODELER_BUILD_SYMBOLS)
		$(INPUTS_BUILD_SYMBOLS)

	For ALs, use:
	=============
		$(COMMON_BUILD_SYMBOLS)
		$(INTEL_MODELER_BUILD_SYMBOLS)
		$(ACTUATORS_BUILD_SYMBOLS)

	For LLs, use:
	=============
		$(COMMON_BUILD_SYMBOLS)
		$(INTEL_MODELER_BUILD_SYMBOLS)
		$(LOGGERS_BUILD_SYMBOLS)

Additional Dependencies (Linker/Input):
=======================================

	For ILs, use:
	=============
		$(XLSDK_INPUT_LIBS)

	For ALs, use:
	=============
		$(XLSDK_ACTUATOR_LIBS)

	For LLs, use:
	=============
		$(XLSDK_LOGGER_LIBS)

	For telemetry, use:
	===================
		$(XLSDK_TELEMETRY_LIBS)

=========================

Debug/Test:
===========
	Command:
	========
		$(XLSDK_RUN)

	Command Arguments:
	==================
		ILs: "--start" "--time_in_ms" "--pause" "1000" "--library" "$(XLSDK_BINS)\intel_modeler.dll" "--no_pl" "--kernel_priority_boost" "--device_options" "time=yes generate_key_file=yes performance=no output=test output_folder='$(XLSDK_OUTPUTS)' il='$(XLSDK_BINS)\$(TargetFileName)' $(XLSDK_RUN_OUTPUT_OPTIONS)"
		ALs: "--start" "--time_in_ms" "--pause" "1000" "--library" "$(XLSDK_BINS)\intel_modeler.dll" "--no_pl" "--kernel_priority_boost" "--device_options" "time=yes generate_key_file=yes performance=no output=test output_folder='$(XLSDK_OUTPUTS)' al='$(XLSDK_BINS)\$(TargetFileName)' il='$(XLSDK_BINS)\incrementing_input.dll' $(XLSDK_RUN_OUTPUT_OPTIONS)"

Build events:
=============
	Post-build Event:
	=================
		Command Line:
		=============
			copy "$(TargetPath)" "$(XLSDK_BINS)"
		Description:
		============
			Copying library to run directory.
		Use in build:
		=============
			Yes

=========================
	
Additional Libraries (may be needed in PATH)
============================================
	OpenCV [x64]
	============
		C:\OpenCV2.4.4\build\$(Platform)\vc10\lib
		C:\OpenCV2.4.4\opencv\build\$(Platform)\vc10\bin

	OpenCV [x86]
	============
		C:\OpenCV2.4.4\build\$(PlatformShortName)\vc10\lib
		C:\OpenCV2.4.4\opencv\build\$(PlatformShortName)\vc10\bin

	PerC
	====
		$(PCSDK_DIR)/lib/$(Platform);$(PCSDK_DIR)/sample/common/lib/$(Platform)/$(PlatformToolset)

	RealSense
	=========
		$(RSSDK_DIR)/lib/$(Platform);$(RSSDK_DIR)/sample/common/lib/$(Platform)/$(PlatformToolset)
