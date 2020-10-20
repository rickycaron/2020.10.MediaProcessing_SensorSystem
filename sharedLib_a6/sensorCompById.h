#ifndef SENSORCOMP_H
#define SENSORCOMP_H

#include <memory>
#include "sensor.h"

struct sensorCompById
{
        bool operator () (const std::shared_ptr<Sensor> & x, const std::shared_ptr<Sensor> & y) const
        {
                if (x->getId()<y->getId())
                        return true;
                else
                        return false;
        }
};

#endif // SENSORCOMPBYID_H

