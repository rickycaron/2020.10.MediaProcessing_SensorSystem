#ifndef GASSENSOR_H
#define GASSENSOR_H
#include "sensor.h"

class GasSensor : public Sensor
{
private:
    string gasType;
public:
    GasSensor(SensorType, string, string);
    void printAllInformation();
    string getAllInformation();
    bool activate();
};

#endif // GASSENSOR_H
