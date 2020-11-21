#pragma once
/**
*** INTEL CONFIDENTIAL
***
*** Copyright (March 2011) (March 2011) Intel Corporation All Rights Reserved.
*** The source code contained or described herein and all documents related to the
*** source code ("Material") are owned by Intel Corporation or its suppliers or
*** licensors. Title to the Material remains with Intel Corporation or its
*** suppliers and licensors. The Material contains trade secrets and proprietary
*** and confidential information of Intel or its suppliers and licensors.
*** The Material is protected by worldwide copyright and trade secret laws
*** and treaty provisions. No part of the Material may be used, copied,
*** reproduced, modified, published, uploaded, posted, transmitted, distributed,
*** or disclosed in any way without Intel's prior express written permission.
***
*** No license under any patent, copyright, trade secret or other intellectual
*** property right is granted to or conferred upon you by disclosure or delivery
*** of the Materials, either expressly, by implication, inducement, estoppel or
*** otherwise. Any license under such intellectual property rights must be
*** express and approved by Intel in writing.
**/

#ifndef __INCLUDE_BATTERY_NEW__
#define __INCLUDE_BATTERY_NEW__

//-----------------------------------------------------------------------------
// Headers inclusions.
//-----------------------------------------------------------------------------
#ifdef __PL_WINDOWS__
#include <windows.h>
#endif // __PL_WINDOWS__
#include "pub_intel_modeler.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	/*--------------------------------------------------------------------------*/

	//-----------------------------------------------------------------------------
	// Defines.
	//-----------------------------------------------------------------------------
#define	INPUTS_COUNT 6
#define AC_INDEX 0
#define BatteryLifeTime_INDEX 1
#define FullLife_INDEX 2
#define BatteryFlag_INDEX 3
#define Status_INDEX 4
#define LifePercent_INDEX 5


#define INPUT_NAME_STRING "BATTERY"

#define INPUT_DESCRIPTION_STRINGS \
	"Battery: AC/DC",\
	"Battery: BatteryLifeTime",\
	"Battery: BatteryFullLifeTime",\
	"Battery: BatteryFlag",\
	"Battery: Status",\
	"Battery: LifePercent"
	
	
#define INPUT_TYPE ULL_COUNTER

//-----------------------------------------------------------------------------
// Function prototypes.
//-----------------------------------------------------------------------------
	ESRV_API ESRV_STATUS modeler_init_inputs(
		unsigned int *,
		int *,
		int *,
		char *,
		size_t
	);
	ESRV_API ESRV_STATUS modeler_open_inputs(PINTEL_MODELER_INPUT_TABLE);
	ESRV_API ESRV_STATUS modeler_close_inputs(PINTEL_MODELER_INPUT_TABLE);
	ESRV_STATUS modeler_read_inputs(PINTEL_MODELER_INPUT_TABLE);
	ESRV_STATUS modeler_listen_inputs(PINTEL_MODELER_INPUT_TABLE);
	ESRV_STATUS modeler_process_dctl(PINTEL_MODELER_INPUT_TABLE);
	ESRV_STATUS modeler_process_lctl(PINTEL_MODELER_INPUT_TABLE);
	/*--------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __INCLUDE_STATIC_STANDARD_INPUT__
