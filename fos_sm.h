#ifndef __FOS_SM_H__
#define __FOS_SM_H__
#include "fos_common.h"
typedef struct _s_st_{
    s_st *next;
    int value;
} s_st;
typedef struct _s_sm_{
   s_sm *next;
    
} s_sm;

#define CREATE_SM(name)       

#define CREATE_ST(sm, st)    

#define CREATE_TRG(sm,from_st, to_st, trg)      

#endif
