#ifndef SENSORCOMPBYVENDOR_H
#define SENSORCOMPBYVENDOR_H

#include <memory>
#include "sensor.h"

struct sensorCompByVendor
{
        bool operator () (const std::shared_ptr<Sensor> & x, const std::shared_ptr<Sensor> & y) const
        {
                if (x->getVendor()<y->getVendor())
                    return true;
                else if(x->getVendor()==y->getVendor()){
                    if(x->getId()<y->getId())
                        return true;
                    else
                        return false;
                }else
                    return false;
        }
};

#endif // SENSORCOMPBYVENDOR_H

