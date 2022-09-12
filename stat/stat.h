#ifndef __STAT_H__
#define __STAT_H__
#include <iostream>

using namespace std;

class Stat {
private:
    int totalHp;
    int remainHp;
    int atk;
    int def;
    int sp;

public:
    Stat();
    Stat(int hp_, int atk_, int def_);
    Stat(int hp_, int atk_, int def_, int sp_);
    int damaged(const Stat& otherStat);
    bool is_dead() const;
    Stat& operator+=(const Stat& otherStat);
    Stat operator+(const Stat& otherStat) const;
    friend ostream& operator<<(ostream& os, const Stat stat);
};
#endif