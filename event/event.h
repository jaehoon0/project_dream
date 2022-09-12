#ifndef __EVENT_H__
#define __EVENT_H__

#include "../character/character.h"
#include <string>

class Event {
private:
    std::string eventName;

public:
    Event(std::string name);
    virtual void event_start(Character& character);
};

#endif