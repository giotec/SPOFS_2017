#pragma once

#define SYSTICK_MSEC_INTERVAL	(10)

#define WHEEL_D_M				(0.557) // metres

#define MAX_RGN_DZ				(0.10)  // V at pin
#define MIN_RGN_DZ				(0.10)
#define MAX_THR_DZ				(0.10)
#define MIN_THR_DZ				(0.10)
#define LOW_PAD_V				(0.25)
#define MID_PAD_V				(1.25)
#define HGH_PAD_V				(2.25)
#define ADC_POINTS_PER_V		(1240.909091)

#define ECONOMY_RAMP_SPEED		(5)
#define SPORTS_RAMP_SPEED		(30)
#define REGEN_RAMP_SPEED		(30)

#define MAX_ESC_CUR				(65.0)  // Amps

#define MAX_REGEN				(350.0) // Maximum available regen - 0 to 1000 (0% to 100%)
#define MAX_THR_DISP			(600.0) // Maximum available throttle in display mode - 0 - 1000 (0% - 100%)
#define MAX_THR_LOWSPD			(750.0) // Maximum available throttle under LOWSPD_THRES - 0 - 1000 (0% - 100%)
#define LOWSPD_THRES			(20.0)  // Threshold speed for low speed throttle cap

#define IIR_GAIN_ELECTRICAL		(1000)
#define IIR_GAIN_THERMAL		(10)