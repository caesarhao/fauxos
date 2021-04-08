#include "fos_mc.h"
#include "list.h"
#ifdef _MC_SUPPORT_
LIST(mc_meas);
LIST(mc_calib);
mc_meas_add(s_mc_meas *item, string namestr){
    list_add(mc_meas, item);
    strcpy(item->name, namestr);
}
void mc_cal_add(s_mc_cal *item, string namestr){
    list_add(mc_cal, item);
    strcpy(item->name, namestr);
}
#endif
