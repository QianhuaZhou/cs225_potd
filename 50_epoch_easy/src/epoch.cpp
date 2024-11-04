#include "epoch.h"
/* Your code here! */

int hours(time_t t){
    return t/3600;
}
int days(time_t t){
     return t/3600/24;
}
int years(time_t t){
     return t/3600/24/365;
}