#ifndef CD4017_H
#define CD4017_H

#include "stdint.h"

//INIT function
void CD4017Init(void);

//Send a pulse to the clock
void CD4017Pulse(void);

//Send a pulse to reset the row's
void CD4017Reset(void);

#endif
