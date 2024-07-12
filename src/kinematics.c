#include "kinematics.h"
#include <math.h>
#include "stdio.h"
#include <string.h>


#define PI 3.1415926f

//extern struct kinematics static_kinematics;

void kinematics_create(kinematics_t km,enum base k_base, float length_x, float length_y, float wheel_radius)
{

    km->k_base        = k_base;
    km->length_x      = length_x;
    km->length_y      = length_y;
    km->circumference = wheel_radius * 2.0f * PI;

    if(k_base == TWO_WD)
    {
    	km->total_wheels = 2;
    }
    if(k_base == FOUR_WD)
    {
    	km->total_wheels = 4;
    }
    if(k_base == ACKERMANN)
    {
    	km->total_wheels = 3;
    }
    if(k_base == THREE)
    {
    	km->total_wheels = 3;
    }
    if(k_base == MECANUM)
    {
    	km->total_wheels = 4;
    }
}

/* Return desired rpm for each motor given target velocity */
void kinematics_get_rpm(struct kinematics kin, struct velocity target_vel, short *rpm)
{

    // TODO
    // struct velocity res_vel;
    struct rpm cal_rpm;
//    short res_rpm[4] = {0};

    float linear_vel_x_mins;
    float linear_vel_y_mins;
    float angular_vel_z_mins;
    float tangential_vel;

    float vel_w1;
    float vel_w2;
    float vel_w3;

    //convert m/s to m/min
    linear_vel_x_mins = target_vel.linear_x ;
    linear_vel_y_mins = target_vel.linear_y ;

    //convert rad/s to rad/min
    angular_vel_z_mins = target_vel.angular_z ;

    //kin.length_x = kin.length_y = r
    tangential_vel = angular_vel_z_mins * kin.length_x ;

    vel_w1 = linear_vel_x_mins + tangential_vel;
    vel_w2 = -0.5f*linear_vel_x_mins + (sqrt(3)/2.f)*linear_vel_y_mins + tangential_vel;
    vel_w3 = -0.5f*linear_vel_x_mins - (sqrt(3)/2.f)*linear_vel_y_mins + tangential_vel;

    cal_rpm.motor1 = vel_w1 / kin.circumference;
    cal_rpm.motor2 = vel_w2 / kin.circumference;
    cal_rpm.motor3 = vel_w3 / kin.circumference;

    rpm[0] = cal_rpm.motor1;
    rpm[1] = cal_rpm.motor2;
    rpm[2] = cal_rpm.motor3;

}

/* Return current velocity given rpm of each motor */
void kinematics_get_velocity(struct kinematics kin, struct rpm current_rpm, struct velocity *velocity)
{
    // TODO
    struct velocity res_vel;

    int total_wheels = 0;
    if(kin.k_base == TWO_WD) total_wheels = 2;
    else if(kin.k_base == FOUR_WD) total_wheels = 4;
    else if(kin.k_base == ACKERMANN) total_wheels = 2;
    else if(kin.k_base == MECANUM) total_wheels = 4;

    float average_rps_x;
    float average_rps_y;
    float average_rps_a;

    //convert average revolutions per minute to revolutions per second
    average_rps_x = ((float)(current_rpm.motor1 + current_rpm.motor2 + current_rpm.motor3 + current_rpm.motor4) / total_wheels) / 60; // RPM
    res_vel.linear_x = average_rps_x * kin.circumference; // m/s

    //convert average revolutions per minute in y axis to revolutions per second
    average_rps_y = ((float)(-current_rpm.motor1 + current_rpm.motor2 + current_rpm.motor3 - current_rpm.motor4) / total_wheels) / 60; // RPM
    if(kin.k_base == MECANUM)
        res_vel.linear_y = average_rps_y * kin.circumference; // m/s
    else
        res_vel.linear_y = 0;

    //convert average revolutions per minute to revolutions per second
    average_rps_a = ((float)(-current_rpm.motor1 + current_rpm.motor2 - current_rpm.motor3 + current_rpm.motor4) / total_wheels) / 60;
    res_vel.angular_z =  (average_rps_a * kin.circumference) / ((kin.length_x / 2) + (kin.length_y / 2)); //  rad/s

    memcpy(velocity, &res_vel, sizeof(struct velocity));
}
