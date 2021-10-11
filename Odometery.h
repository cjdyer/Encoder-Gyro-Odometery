#ifndef ODOMETERY_H
#define ODOMETERY_H

#include <stdint.h>

class Odometery
{
public:
    Odometery(const uint8_t _id);
    uint8_t GetID();
    double GetX();
    double GetY();
    void CalculatePosition(const int32_t _left_encoder,const int32_t _right_encoder, const int32_t _tracking_encoder, const float _gyroscope);
private:
    const uint8_t id_;

    double global_x_, global_y_;

    static constexpr double degrees_to_radians_ = 3.14159265358979323846 / 180; // pi / 180
};

#endif