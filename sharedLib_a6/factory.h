#ifndef VENDORAFACTORY_H
#define VENDORAFACTORY_H

#include "smokesensor.h"
#include "motionsensor.h"
#include "gassensor.h"

class Factory
{    
public:
    Factory();
<<<<<<< HEAD
    Factory(string);
    string getFactoryName() const;
    void setFactoryName(const string &value);
    std::unique_ptr<SmokeSensor> createSmokeSensor() ;
    std::unique_ptr<MotionSensor> createMotionSensor(tm activationTime,tm deactivationTime,int restrication);
    std::unique_ptr<MotionSensor> createMotionSensor(bool);
    std::unique_ptr<GasSensor> createGasSensor(string) ;
=======
   virtual std::shared_ptr<SmokeSensor> createSmokeSensor() =0;
   virtual std::shared_ptr<MotionSensor> createMotionSensor(tm activationTime,tm deactivationTime,int restrication)=0;
   virtual std::shared_ptr<GasSensor> createGasSensor(string)=0;

>>>>>>> cdf6c2b75b6a44a9b95b48b89e32c8c5dc28566c
private:
    string factoryName;
};
//hello!!!!!!!
#endif
