#include "motionsensor.h"

MotionSensor::MotionSensor(SensorType stringtype, string vendor):Sensor(stringtype,vendor){}

MotionSensor::MotionSensor(SensorType stringtype, string vendor,tm activetime,tm deactivetime):Sensor(stringtype,vendor),activationTime(activetime),deactivationTime(deactivetime){}

MotionSensor::MotionSensor(SensorType stringtype, string vendor,bool permenentactive):Sensor(stringtype,vendor),permenateActive(permenentactive){}

MotionSensor::MotionSensor(SensorType stringtype, string vendor,tm activetime,tm deactivetime,int restrication):Sensor(stringtype,vendor),activationTime(activetime),deactivationTime(deactivetime),restrication(restrication){}

void MotionSensor::printAllInformation()
{
    cout<<getAllInformation()<<endl;
}

string MotionSensor::getAllInformation()
{
    std::stringstream sensorInformation;
    sensorInformation <<"Motion sensor to detect of id "<<id<<" ,produce by "<<vendor<<" is ";
    if(permenateActive) sensorInformation<<"permenate acitve ,";
        else if (activationTime.tm_hour!= deactivationTime.tm_hour && activationTime.tm_hour!=0)
        {
            sensorInformation<<"active from "<< activationTime.tm_hour<<":"<<activationTime.tm_min<<" to "<<deactivationTime.tm_hour<<" : "<<deactivationTime.tm_min<<" ,";
        }
        if(!restrication) sensorInformation<<"has a restricaiton of "<<restrication<<" meters ";
        if(activationState)
            sensorInformation<<"is active now! ";
        else
            sensorInformation<<"is not active now! ";
    return sensorInformation.str();

}

bool MotionSensor::activate()
{
    if(sensorType == ST_MotionSensor)
    {
        activationState=checktime();
        return activationState;
    }
    else{
        activationState=checktime();
        return activationState;
    }
}

bool MotionSensor::checktime()
{
    const time_t now=time(nullptr);
    const tm tmnow=*localtime(addressof(now));
    int hournow=tmnow.tm_hour;
    int minnow=tmnow.tm_min;
    bool result=false;
    int acthour=activationTime.tm_hour;
    int actmin=activationTime.tm_min;
    int deacthour=deactivationTime.tm_hour;
    int deactmin=deactivationTime.tm_min;

    if(permenateActive){result=true;}
    else if(acthour == deacthour && actmin==deactmin)
        {
        cout<<"Wong activation and deactivation time for motion sensor of id "<<id<<"endl";
        result= false;
        }
    else
    {

        if(acthour > deacthour)
        {
            if(hournow > acthour ||( (hournow == acthour) && (minnow > actmin)))
            {result=true;}
            else if(hournow<deacthour||(hournow==deacthour &&minnow <= actmin))
            {result=true;}
        }
        else if (acthour < deacthour)
        {
            if(hournow > acthour && hournow < deacthour)
                {result=true;}
            else if (hournow==acthour && minnow >= actmin)
                {result=true;}
            else if(hournow==deacthour && minnow <=deactmin)
                {result=true;}
        }
        else if(acthour == deacthour)
        {
            if (hournow==acthour && minnow >= actmin && minnow <= deactmin)
                {result=true;}
        }
        else
           {result=false;}
    }

    return result;
}
