
#ifndef __KINEMATICS_H__
#define __KINEMATICS_H__

//#include "main.h"

#define WHEEL_DIST_X  0.175f
#define WHEEL_DIST_Y  0.086f
#define WHEEL_RADIUS  0.022f
//#define GEAR_RATIO    1

enum base {
    TWO_WD = 0, 
    FOUR_WD, 
    ACKERMANN, 
    MECANUM,
		THREE
};

// rad/min
struct rpm
{
    int motor1;
    int motor2;
    int motor3;
    int motor4;
};

// m/s
struct velocity
{
    float linear_x;
    float linear_y;
    float angular_z;
};

typedef struct kinematics *kinematics_t;

struct kinematics
{
    enum base   k_base;
    float       length_x;
    float       length_y;
    float       circumference;
    int         total_wheels;
};

void    kinematics_create(kinematics_t kt, enum base k_base, float length_x, float length_y, float wheel_radius);
//void            kinematics_destroy(kinematics_t kinematics);
//long        kinematics_reset(kinematics_t kin);

void            kinematics_get_rpm(struct kinematics kin, struct velocity target_vel, short *rpm);
void            kinematics_get_velocity(struct kinematics kin, struct rpm current_rpm, struct velocity *velocity);

#endif
