#ifndef SINGLE_H
#define SINGLE_H

#include "unit.h"

class Sensor;
class Single : public Unit
{
public:
    Single(std::string_view name);
    void triggered() override;
    bool isGroup() override{return false;};
    std::shared_ptr<Sensor> getSensor() override;
    void setSensor(const std::shared_ptr<Sensor> &value);
    Single & operator ++();
    Single &operator --();
    void activate() override;
    void deactivate() override;
private:
    std::shared_ptr<Sensor> sensor;
};

#endif // SINGLE_H

