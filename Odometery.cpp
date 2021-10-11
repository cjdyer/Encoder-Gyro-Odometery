#include "Odometery.h"

Odometery::Odometery(const uint8_t _id) : 
    id_(_id)
{
}

uint8_t Odometery::GetID() { return id_; }