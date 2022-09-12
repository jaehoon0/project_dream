#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "../monster/monster.h"
#include "../character/character.h"
#include "../weapon/weapon.h"
#include "../event/event.h"
#include "../event/events/koh/koh.h"
#include "../event/events/merchant/merchant.h"
#include <vector>

class Manager {
private:
    int chapterIndex;
    int scenarioIndex;
    vector<Monster> monsters[4];
    vector<Weapon> weapons[2];
    vector<bool> isEncounter[2];
    int encounterBit[2];
public:
    Manager();
    Manager(int chapterIndex);
    void generate_event(Character& character);
    Monster generate_enemy(int& monsterLevel);
    void battle(Character& character);
    void normal_event(Character& character);
    void show_status(const Character& character, const Monster& enemy) const;
    bool is_clear();
};
    
#endif