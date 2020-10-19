#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H
#include "sensor.h"
#include <ctime>

class MotionSensor: public Sensor
{
private:
    bool permenateActive=false;
    tm activationTime={0};
    tm deactivationTime={0};
    int restrication=0;
public:
    MotionSensor(SensorType,string);
    MotionSensor(SensorType,string,tm,tm);
    MotionSensor(SensorType,string,bool);
    MotionSensor(SensorType,string,tm,tm,int);
    void printAllInformation();
    string getAllInformation();
    bool activate();// reload activate() fuction in Sensor
    void deactive();

    bool checktime();//check from time is it should be active or inactive now
};

#endif // MOTIONSENSOR_H
