#include <cmath>
#include "Odometery.h"

Odometery::Odometery(const uint8_t _id) : 
    id_(_id)
{
}

uint8_t Odometery::GetID() { return id_; }
double Odometery::GetX() {return global_x_; }
double Odometery::GetY() {return global_y_; }

template <typename EncoderUnits>
void Odometery::CalculatePosition(const EncoderUnits _left_encoder,const EncoderUnits _right_encoder, const EncoderUnits _tracking_encoder, const float _gyroscope)
{
    static EncoderUnits 
    local_vertical_position, local_horizontal_position, 
    change_x, change_y, 
    prev_local_horizontal_position, prev_local_vertical_position;
    static double global_change_x, global_change_y, gyroscope_radians;

    local_vertical_position = (_left_encoder + _right_encoder) / 2;
    local_horizontal_position = _tracking_encoder;

    change_x = local_horizontal_position - prev_local_horizontal_position;
    change_y = local_vertical_position - prev_local_vertical_position;

    prev_local_horizontal_position = local_horizontal_position;
    prev_local_vertical_position = local_vertical_position;

    gyroscope_radians = _gyroscope * degrees_to_radians_;
    global_change_x = change_y * sin(gyroscope_radians) - change_x * cos(gyroscope_radians);
	global_change_y = change_x * sin(gyroscope_radians) - change_y * cos(gyroscope_radians);

    global_x_ += global_change_x;
    global_y_ += global_change_y;
}