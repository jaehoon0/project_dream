#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "../creature/creature.h"

class Character:public Creature {
public:
    Character();
    Character(string name);
    Character(string name, int hp_, int atk_, int def_,  int sp_);
    virtual void attacked(const Creature& enemy);
    virtual void showStatus() const;
};

#endif