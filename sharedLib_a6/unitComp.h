#ifndef UNITCOMP_H
#define UNITCOMP_H
#include <memory>
#include "unit.h"

struct UnitComp
{
        bool operator () (const std::shared_ptr<Unit> & x, const std::shared_ptr<Unit> & y) const
        {
                if (x->getUnitName().compare(y->getUnitName()) < 0)
                        return true;
                else
                        return false;
        }
};

#endif // UNITCOMP_H
