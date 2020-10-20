#ifndef SINGLE_H
#define SINGLE_H

#include "unit.h"

class Sensor;
class Single : public Unit
{
using Unit::Unit;
public:
    void triggered() override;
    bool isGroup() override{return false;};
    std::shared_ptr<Sensor> getSensor() const override;
    void setSensor(const std::shared_ptr<Sensor> &value);
    Single & operator ++() override;
    Single & operator --() override;
private:
    std::shared_ptr<Sensor> sensor;
};

#endif // SINGLE_H

