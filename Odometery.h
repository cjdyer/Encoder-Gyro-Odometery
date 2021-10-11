#ifndef ODOMETERY_H
#define ODOMETERY_H

#include <stdint.h>

/**
 * Implementation of odometery in C++
 *
 * Given the following three encoders and a heading it will calculate a rough cartesian position.
 * 
 * Information required:
 * 
 * Left Encoder
 * Right Encoder
 * Tracking/Horizontal Encoder
 * Heading Angle (Gyroscope)
 * 
 * This code should not be used as an APS (absolute positioning system), but can be used to
 * give a rough robot position for use with other sensor information or robot data.
 *
 */
class Odometery
{
public:
    /**
     * @brief Creates an odometery object
     */
    Odometery();

    /**
     * @brief Gets the estimated X position of the robot
     * 
     * @return The X positon of the robot
     */
    double GetX();

    /**
     * @brief Gets the estimated Y position of the robot
     * 
     * @return The Y positon of the robot
     */
    double GetY();

    /**
     * @brief Calculate the position of the robot
     * 
     * @tparam The units used when interfacing with the encoders, likely int32_t 
     * @param _left_encoder The left encoder value
     * @param _right_encoder The right encoder value
     * @param _tracking_encoder The horizontal/tracking encoder value
     * @param _gyroscope The gyroscope value, assumed 1 deg = 1.0
     */
    template <typename EncoderUnits>
    void CalculatePosition(const EncoderUnits _left_encoder,const EncoderUnits _right_encoder, const EncoderUnits _tracking_encoder, const float _gyroscope);

private:

    double global_x_, global_y_; // The global X/Y position

    static constexpr double degrees_to_radians_ = 3.14159265358979323846 / 180; // pi / 180
};

#endif