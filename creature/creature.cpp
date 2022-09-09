#include "creature.h"

Creature::Creature(): name("UnKnOwN") {};

Creature::Creature(string name_):name(name_) {};

Creature::Creature(string name_, int hp_, int atk_, int def_):name(name_), stat(hp_, atk_, def_) {};

Creature::Creature(string name_, int hp_, int atk_, int def_, int sp_):name(name_), stat(hp_, atk_, def_, sp_) {};

Stat Creature::get_stat() const {
    return stat;
}

void Creature::attacked(const Creature& enemy) {
    stat.damaged(enemy.stat);
}