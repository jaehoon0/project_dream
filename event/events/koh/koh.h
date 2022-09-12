#ifndef __KOH_H__
#define __KOH_H__

#include "../../event.h"
#include "../../../weapon/weapon.h"

class Koh:public Event {
private:
    string ment;
public:
    Koh();
    virtual void event_start(Character& character);
};

#endif