#ifndef SENSORCOMP_H
#define SENSORCOMP_H

#include <memory>
#include "sensor.h"
#include "unit.h"

struct sensorCompById
{
        bool operator () (const std::shared_ptr<Unit> & x, const std::shared_ptr<Unit> & y) const
        {
                if (x->getSensor()->getId()<y->getSensor()->getId())
                        return true;
                else
                        return false;
        }
};

#endif // SENSORCOMPBYID_H

