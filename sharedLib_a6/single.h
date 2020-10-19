#ifndef SINGLE_H
#define SINGLE_H

#include "unit.h"

class Sensor;
class Single : public Unit
{
public:
    Single(std::shared_ptr<Unit> parent, std::string_view name,std::unique_ptr<Sensor> sensor);

    void setSensor(std::unique_ptr<Sensor> value);

private:
    std::unique_ptr<Sensor> sensorPointer;
    bool isGroup() const override;
    void triggered() const override;
    //void print() const override;
};

#endif // SINGLE_H
