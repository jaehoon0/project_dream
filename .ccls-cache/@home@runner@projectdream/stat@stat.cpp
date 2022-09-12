#include <iostream>
#include "stat.h"

using namespace std;

Stat::Stat():totalHp(0), remainHp(0), atk(0), def(0), sp(0) {}

Stat::Stat(int hp_, int atk_, int def_):totalHp(hp_), remainHp(hp_), atk(atk_), def(def_), sp(0) {};

Stat::Stat(int hp_, int atk_, int def_, int sp_):totalHp(hp_), remainHp(hp_), atk(atk_), def(def_), sp(sp_) {};

void Stat::damaged(const Stat& otherStat) {
    int giveDamage=otherStat.atk*((double)otherStat.atk/def);
    remainHp=remainHp-giveDamage>0 ? remainHp-giveDamage : 0;
}

bool Stat::is_dead() const {
    return remainHp<=0;    
}

Stat& Stat::operator+=(const Stat& otherStat) {
    if(this->totalHp==0) {
        this->remainHp=0;
    }
    else {
        double hpRatio=(double)this->remainHp / this->totalHp;
        this->totalHp+=otherStat.totalHp;
        this->remainHp=this->totalHp*hpRatio;        
    }
    this->atk+=otherStat.atk;
    this->def+=otherStat.def;
    return *this;
}

Stat Stat::operator+(const Stat& otherStat) const {
    int resultHp=totalHp+otherStat.totalHp;
    int resultAtk=atk+otherStat.atk;
    int resultDef=def+otherStat.def;
    Stat resultStat(resultHp, resultAtk, resultDef);
    return resultStat;
}

ostream& operator<<(ostream& os, const Stat stat) {
    cout<<"< Stat >"<<endl;
    cout<<"HP  ---------- "<<stat.remainHp<<'/'<<stat.totalHp<<endl;
    cout<<"ATK ---------- "<<stat.atk<<endl;
    cout<<"DEF ---------- "<<stat.def<<endl;
    cout<<"==================="<<endl;
    return os;
}