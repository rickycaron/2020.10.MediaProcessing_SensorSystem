#include "gassensor.h"


GasSensor::GasSensor(SensorType stringtype, string vendor, string gastype):Sensor(stringtype,vendor),gasType(gastype)
{}

void GasSensor::printAllInformation()
{
    cout<<"Gas sensor to detect "<<gasType<<" ,of id "<<id<<" ,produce by "<<vendor<<" is ";
    if(activationState)
        cout<<"active now! ";
    else
        cout<<"not active now! ";
    cout<<endl;
}

string GasSensor::getAllInformation()
{
    std::stringstream sensorInformation;
    sensorInformation <<"Gas sensor to detect "<<gasType<<" ,of id "<<id<<" ,produce by "<<vendor<<" is ";
    if(activationState)
       sensorInformation<<"active now! ";
    else
        sensorInformation<<"not active now! ";
    return sensorInformation.str();

}

bool GasSensor::activate()
{
    activationState=true;
    return activationState;
}
