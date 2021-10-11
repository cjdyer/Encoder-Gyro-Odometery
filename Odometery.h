#ifndef ODOMETERY_H
#define ODOMETERY_H

#include <stdint.h>

class Odometery
{
public:
    Odometery(const uint8_t _id);
    uint8_t GetID();
private:
    const uint8_t id_;
};

#endif