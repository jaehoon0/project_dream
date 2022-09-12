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
        cout<<"< --- 꿈도로에 도착했습니다! --- >"<<endl;
        while(!player.is_dead()) {
            cout<<"이 잎은 위험하지만 더 간다면 좋은 보상을 얻을 수도 있어..."<<endl;
            cout<<"어떻게 하는게 좋을까?!?"<<endl;
            cout<<"============================================="<<endl;
            cout<<"1. 위험을 감수하고 조금 더 가본다"<<endl;
            cout<<"2. 다음 별로 이동한다"<<endl;
            cout<<"============================================="<<endl;
            int input;
            cin>>input;
            if(input==2) break;
            manager.generate_event(player);
        }
        
        scen=new Reader(scenarioAdd+to_string(chapter)+"-2.txt");
        scen->read();
        delete scen;
    }
    return 0;
}