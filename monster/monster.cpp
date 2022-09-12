#include "monster.h"

Monster::Monster() {}

Monster::Monster(string name):Creature(name) {}

Monster::Monster(string name, int hp_, int atk_, int def_): Creature(name, hp_, atk_, def_){}

Monster::Monster(string name, int hp_, int atk_, int def_,  int sp_): Creature(name, hp_, atk_, def_, sp_) {}

Stat Monster::get_stat() const {
    return stat;
}

void Monster::attacked(const Creature& enemy) {
    stat.damaged(enemy.get_stat());
}

void Monster::show_status() const {
    cout<<name<<"(Monster)"<<endl;
    cout<<stat;
}

bool Monster::is_dead() const {
    return stat.is_dead();
}