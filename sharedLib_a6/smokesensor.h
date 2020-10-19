#ifndef SMOKESENSOR_H
#define SMOKESENSOR_H
#include "sensor.h"

class SmokeSensor: public Sensor
{
public:
    SmokeSensor(SensorType,string);
    bool activate();
    string getAllInformation();
    void printAllInformation();
};

#endif // SMOKESENSOR_H
