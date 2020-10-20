#include "smokesensor.h"

SmokeSensor::SmokeSensor(SensorType sensorType, string vendor): Sensor(sensorType,vendor)
{

}

string SmokeSensor::getAllInformation()
{
    std::stringstream sensorInformation;
    sensorInformation <<"Smoke sensor of id "<<id<<" is produce by "<<vendor<<"is ";
    if(activationState)
       sensorInformation<<"active now! ";
    else
        sensorInformation<<"not active now! ";
    return sensorInformation.str();
}

void SmokeSensor::printAllInformation()
{
    cout<<"Smoke sensor of id "<<id<<" is produce by "<<vendor<<"is ";
    if(activationState)
        cout<<"active now! ";
    else
        cout<<"not active now! ";
    cout<<endl;
}

bool SmokeSensor::activate()
{
    activationState=true;
    return activationState;
}
