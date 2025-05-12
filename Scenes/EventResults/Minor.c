#ifndef CUSTOM_VS_MINOR_C
#define CUSTOM_VS_MINOR_C

#include "Minor.h"
#include "gobj.h"

void* data;

void minor_think(){
    Match_Think();

    return;
}

void minor_load(void* minor_data){
    OSReport("minor load\n");
    data = minor_data;
    Match_Enter(data);
    return;
}


void minor_exit(void* minor_data){
    Match_Exit(minor_data);
    return;
}


#endif CUSTOM_VS_MINOR_C
