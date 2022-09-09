#include "stat/stat.h"
#include "creature/creature.h"
#include "character/character.h"
#include "monster/monster.h"
#include <iostream>

int main() {
    Character a("a", 10, 2, 3, 2);
    Monster b("b", 8, 4, 2);
    a.attacked(b);
    a.showStatus();
}