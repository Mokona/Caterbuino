#include "data.h"

const uint16_t caterpillar[] = {
    8, 8,
    5, 0,
    0, 0,
    0x0, 0x0, 0x380, 0x380, 0x380, 0x380, 0x0, 0x0, 0x0, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x0, 0x380, 0x380, 0x440, 0x440, 0x440, 0x440, 0x380, 0x380, 0x380, 0x380, 0x440, 0x540, 0x540, 0x440, 0x380, 0x380, 0x380, 0x380, 0x440, 0x540, 0x540, 0x440, 0x380, 0x380, 0x380, 0x380, 0x440, 0x440, 0x440, 0x440, 0x380, 0x380, 0x0, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x0, 0x0, 0x0, 0x380, 0x380, 0x380, 0x380, 0x0, 0x0, 0x0, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x0, 0x380, 0x380, 0x440, 0x440, 0x440, 0x440, 0x440, 0x440, 0x380, 0x380, 0x440, 0x440, 0xffff, 0x0, 0x440, 0x540, 0x380, 0x380, 0x440, 0x440, 0x440, 0x440, 0x440, 0x380, 0x380, 0x380, 0x440, 0x440, 0x440, 0x440, 0x440, 0x380, 0x380, 0x380, 0x440, 0x440, 0xffff, 0x0, 0x440, 0x540, 0x380, 0x380, 0x440, 0x440, 0x440, 0x440, 0x440, 0x440, 0x0, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x0, 0x0, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x0, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x440, 0x440, 0x440, 0x440, 0x440, 0x440, 0x380, 0x380, 0x440, 0x440, 0x440, 0x440, 0x440, 0x440, 0x380, 0x380, 0x440, 0xffff, 0x440, 0x440, 0xffff, 0x440, 0x380, 0x380, 0x440, 0x0, 0x440, 0x440, 0x0, 0x440, 0x380, 0x380, 0x440, 0x440, 0x440, 0x440, 0x440, 0x440, 0x380, 0x0, 0x440, 0x540, 0x380, 0x380, 0x540, 0x440, 0x0, 0x0, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x0, 0x440, 0x440, 0x440, 0x440, 0x440, 0x440, 0x380, 0x380, 0x540, 0x440, 0x0, 0xffff, 0x440, 0x440, 0x380, 0x380, 0x380, 0x440, 0x440, 0x440, 0x440, 0x440, 0x380, 0x380, 0x380, 0x440, 0x440, 0x440, 0x440, 0x440, 0x380, 0x380, 0x540, 0x440, 0x0, 0xffff, 0x440, 0x440, 0x380, 0x380, 0x440, 0x440, 0x440, 0x440, 0x440, 0x440, 0x380, 0x380, 0x0, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x0, 0x0, 0x440, 0x540, 0x380, 0x380, 0x540, 0x440, 0x0, 0x380, 0x440, 0x440, 0x440, 0x440, 0x440, 0x440, 0x380, 0x380, 0x440, 0x0, 0x440, 0x440, 0x0, 0x440, 0x380, 0x380, 0x440, 0xffff, 0x440, 0x440, 0xffff, 0x440, 0x380, 0x380, 0x440, 0x440, 0x440, 0x440, 0x440, 0x440, 0x380, 0x380, 0x440, 0x440, 0x440, 0x440, 0x440, 0x440, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x0, 0x380, 0x380, 0x380, 0x380, 0x380, 0x380, 0x0
};

const uint16_t* getCaterpillarData()
{
    return reinterpret_cast<const uint16_t*>(caterpillar);
}
