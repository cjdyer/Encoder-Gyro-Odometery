#include <cmath>
#include "Odometery.h"

Odometery::Odometery(const uint8_t _id) : 
    id_(_id)
{
}

uint8_t Odometery::GetID() { return id_; }
double Odometery::GetX() {return global_x_; }
double Odometery::GetY() {return global_y_; }

void Odometery::CalculatePosition(const int32_t _left_encoder,const int32_t _right_encoder, const int32_t _tracking_encoder, const float _gyroscope)
{
    static int32_t 
    local_vertical_position, local_horizontal_position, 
    change_x, change_y, 
    prev_local_horizontal_position, prev_local_vertical_position;
    static double global_change_x, global_change_y;

    local_vertical_position = (_left_encoder + _right_encoder) / 2;
    local_horizontal_position = _tracking_encoder;

    change_x = local_horizontal_position - prev_local_horizontal_position;
    change_y = local_vertical_position - prev_local_vertical_position;

    prev_local_horizontal_position = local_horizontal_position;
    prev_local_vertical_position = local_vertical_position;

    global_change_x = change_x * cos(-_gyroscope * degrees_to_radians_) - change_y * sin(-_gyroscope * degrees_to_radians_);
	global_change_y = change_x * sin(_gyroscope * degrees_to_radians_) - change_y * cos(_gyroscope * degrees_to_radians_);

    global_x_ += global_change_x;
    global_y_ += global_change_y;
}