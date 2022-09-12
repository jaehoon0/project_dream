#include "stat/stat.h"
#include "creature/creature.h"
#include "character/character.h"
#include "monster/monster.h"
#include "manager/manager.h"
#include "reader/reader.h"
#include <iostream>
#include <fstream>

const int chapterNum=2;
const string scenarioAdd="./data/program_data/scenario/chapter";

//cout << "\x1B[2J\x1B[H";

string getStart();

int main() {
    //초기 설정
    Reader* scen=new Reader(scenarioAdd+"_start1.txt");
    scen->read();
    delete scen;
    
    cout<<"---당신의 이름을 입력해 주세요--- >> ";
    string pName;
    cin>>pName;
    Character player(pName, 15, 5, 5, 0);
    
    scen=new Reader(scenarioAdd+"_start2.txt");
    scen->read();
    delete scen;
    
    for(int chapter=0; chapter<chapterNum; chapter++) {
        if(chapter==0) {
            scen=new Reader(scenarioAdd+to_string(chapter)+".txt");
            scen->read();
            delete scen;
            continue;
        }
        scen=new Reader(scenarioAdd+to_string(chapter)+"-1.txt");
        scen->read();
        delete scen;
        
        Manager manager(chapter);
        while(!manager.is_clear() && !player.is_dead())
            manager.generate_event(player);
        
        if(player.is_dead()) break;
        
        scen=new Reader(scenarioAdd+to_string(chapter)+"-2.txt");
        scen->read();
        delete scen;
    }
    return 0;
}