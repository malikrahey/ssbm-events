#ifndef CUSTOM_VS_MINOR_H
#define CUSTOM_VS_MINOR_H

#include "../../m-ex/MexTK/mex.h"

// functions
static void* (*Match_Think)() = (void *) 0x8016d800;
static void* (*Match_Enter)(MatchInit *data) = (void *) 0x8016e934;
static void* (*Match_Exit)(MatchInit *data) = (void *) 0x8016e9c8;

#endif CUSTOM_VS_MINOR_H