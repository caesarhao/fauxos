#ifndef __FOS_MC_H__
#define __FOS_MC_H__
/**
 * Support of Measurement and Calibration
 */
#include "fos_macro.h"

#ifdef _MC_SUPPORT_
void mc_meas_add(void *addr, int size, string namestr);
void mc_measarr_add(void *addr, int size, int len, string namestr); 
#define DEF_VAR(type, name)    type name; \
                                mc_meas_add(&name, sizeof(type), STRER(name))
#define DEF_ARR(type, name, len)    type name[len]; \
                                mc_measarr_add(&name[0], sizeof(type), len, STRER(name)) 
#else
#define DEF_VAR(type, name)    type name;
#define DEF_ARR(type, name, size)    type name[size]; 
#endif

#endif
