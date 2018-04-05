#include "seed.h"

// As including Arduino.h with C++ code tend to cause conflicts
// seed.cpp is only used to put aside call to system to get a seed
#include "Arduino.h"

uint32_t get_seed()
{
    return micros();
}
