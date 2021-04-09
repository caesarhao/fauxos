#ifndef __FOS_MC_H__
#define __FOS_MC_H__
/**
 * Support of Measurement and Calibration
 */
#include "fos_common.h"

#ifdef _MC_SUPPORT_
#define MC_NAME_MAXSIZE    (15)
typedef struct _s_mc_meas_{
   s_mc_meas *next; 
   void *address;
   int size;
   char name[MC_NAME_MAXSIZE+1]; 
} s_mc_meas;

typedef struct _s_mc_cal_{
   s_mc_cal *next; 
   void *address;
   int size;
   char name[MC_NAME_MAXSIZE+1];  
} s_mc_cal;

void mc_meas_add(s_mc_meas *item, string namestr);
void mc_cal_add(s_mc_cal *item, string namestr); 

#define GET_MEAS(meas)  (meas)

#define DEF_MEAS(type, name, value)     type name = value; \
                                        s_mc_meas CONCAT2(s_mc_meas_, name) = \
                                        {NULL, &name, sizeof(type), STRER(name)}

#define INIT_MEAS(name)                 mc_meas_add(&name, STRER(name)) 

#define GET_CAL(x)    (CONCAT2(x, _C))

#define DEF_CAL(type, name, value)    const type name = value; \
                                       type CONCAT2(x, _C) = value; \
                                       s_mc_cal CONCAT2(s_mc_cal_, name) = \
                                       {NULL, &name, sizeof(type), STRER(name)} 

#define INIT_CAL(name)              mc_cal_add(&name, STRER(name))  

#else

#define GET_MEAS(meas)  (meas)

#define DEF_MEAS(type, name, value)     type name = value

#define INIT_MEAS(name)     

#define GET_CAL(con)    (con)

#define DEF_CAL(type, name, value)    const type name = value

#define INIT_CAL(name)     

#endif

#endif
