#ifndef SENSORCOMPBYVENDOR_H
#define SENSORCOMPBYVENDOR_H

#include <memory>
#include "sensor.h"
#include "unit.h"

struct sensorCompByVendor
{
        bool operator () (const std::shared_ptr<Unit> & x, const std::shared_ptr<Unit> & y) const
        {
                if (x->getSensor()->getVendor()<y->getSensor()->getVendor())
                    return true;
                else if(x->getSensor()->getVendor()==y->getSensor()->getVendor()){
                    if(x->getSensor()->getId()<y->getSensor()->getId())
                        return true;
                    else
                        return false;
                }else
                    return false;
        }
};

#endif // SENSORCOMPBYVENDOR_H

