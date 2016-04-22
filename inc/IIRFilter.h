/*
 * IIRFilter.h
 *
 *  Created on: Apr 15, 2016
 *      Author: Stuff
 */

#ifndef IIRFILTER_H_
#define IIRFILTER_H_

#include "LPC17xx.h"

/******************************************************************************
 ** Function name:  iir_filter_uint
 **
 ** Description:    Filter to flatten out erratic data reads
 **
 ** Parameters:     1. Input data
 **                 2. Existing data
 **                 3. Gain factor
 ** Returned value: Smoothed value
 **
 ******************************************************************************/
inline uint32_t iir_filter_uint (uint32_t _data_in, uint32_t _cur_data, uint16_t _gain)
{return (((_gain-1)*_cur_data)+_data_in)/_gain;}

/******************************************************************************
 ** Function name:  iir_filter_int
 **
 ** Description:    Filter to flatten out erratic data reads
 **
 ** Parameters:     1. Input data
 **                 2. Existing data
 **                 3. Gain factor
 ** Returned value: Smoothed value
 **
 ******************************************************************************/
inline int32_t iir_filter_int (int32_t _data_in, int32_t _cur_data, uint16_t _gain)
{return (((_gain-1)*_cur_data)+_data_in)/_gain;}

/******************************************************************************
 ** Function name:  iir_filter_float
 **
 ** Description:    Filter to flatten out erratic data reads
 **
 ** Parameters:     1. Input data
 **                 2. Existing data
 **                 3. Gain factor
 ** Returned value: Smoothed value
 **
 ******************************************************************************/
inline float iir_filter_float (float _data_in, float _cur_data, uint16_t _gain)
{return (((_gain-1)*_cur_data)+_data_in)/_gain;}


#endif /* IIRFILTER_H_ */
