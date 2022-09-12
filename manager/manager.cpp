#include "manager.h"
#include <fstream>
#include <sstream>
#include <string>
#include <random>

using namespace std;

namespace manager {
    void get_enter() {
        char next='n';
        while(next!='\n')
            cin.get(next);
    }
}

Manager::Manager():chapterIndex(1), scenarioIndex(1) {
    ifstream monsterData("./data/program_data/monster/chapter1.txt");

    char line[500];
    while(monsterData.getline(line, sizeof(line))) {        
        int start=0;
        string separator="/";
        string data=string(line);
        int divideIndex=data.find(separator);
        vector<string> temp;
        
        while(divideIndex!=-1) {
            temp.push_back(data.substr(start, divideIndex-start));
            start=divideIndex+1;
            divideIndex = data.find(separator, start);
        }
        temp.push_back(data.substr(start, divideIndex-start));

        int hp, atk, def;
        stringstream hpInt(temp[1]);
	    hpInt >> hp;
        stringstream atkInt(temp[2]);
	    atkInt >> atk;
        stringstream defInt(temp[3]);
	    defInt >> def;

        Monster monster(temp[0], hp, atk, def);
        monsters[temp[4][0]-'0'].push_back(monster);

    }
    monsterData.close();

    for(int i=0; i<2; i++) {
        int totalBit=0;
        for(int j=0; j<monsters[2+i].size(); j++) {
            isEncounter[i].push_back(false);
            int monsterBit=1<<j;
            totalBit+=monsterBit;
        }
        encounterBit[i]=totalBit;
    }
}

Manager::Manager(int chapterIndex):chapterIndex(chapterIndex), scenarioIndex(1) {
    string chapterAdd="./data/program_data/monster/chapter"+to_string(chapterIndex)+".txt";
    ifstream monsterData(chapterAdd);

    char line[500];
    while(monsterData.getline(line, sizeof(line))) {        
        int start=0;
        string separator="/";
        string data=string(line);
        int divideIndex=data.find(separator);
        vector<string> temp;
        
        while(divideIndex!=-1) {
            temp.push_back(data.substr(start, divideIndex-start));
            start=divideIndex+1;
            divideIndex = data.find(separator, start);
        }
        temp.push_back(data.substr(start, divideIndex-start));

        int hp, atk, def;
        stringstream hpInt(temp[1]);
	    hpInt >> hp;
        stringstream atkInt(temp[2]);
	    atkInt >> atk;
        stringstream defInt(temp[3]);
	    defInt >> def;

        Monster monster(temp[0], hp, atk, def);
        monsters[temp[4][0]-'0'].push_back(monster);

    }
    monsterData.close();

    for(int i=0; i<2; i++) {
        int totalBit=0;
        for(int j=0; j<monsters[2+i].size(); j++) {
            isEncounter[i].push_back(false);
            int monsterBit=1<<j;
            totalBit+=monsterBit;
        }
        encounterBit[i]=totalBit;
    }
}

void Manager::generate_event(Character& character) {
    random_device rd;
    mt19937 gen(rd());    
    uniform_int_distribution<int> typeDis(1, 100);
    
    int selectEvent=typeDis(gen);

    if(selectEvent<31) {
        normal_event(character);
    }
    else {
        battle(character);
    }
}

Monster Manager::generate_enemy(int& monsterLevel) {
    //확률 계산
    int rate[4]={100, 0, 0, 0};
    int standard[4]={50, 30, 15, 5};
    int scenarioPoint=scenarioIndex;

    for(int i=0; i<3; i++) {
        if(scenarioPoint<=0)
            break;
        rate[i]-=scenarioPoint;
        rate[i+1]+=scenarioPoint;
        scenarioPoint=0;

        if(rate[i]<standard[i]) {
            int gap=standard[i]-rate[i];
            rate[i]=standard[i];
            rate[i+1]-=gap;
            scenarioPoint+=gap;
        }
    }
    rate[3]=min(rate[3], standard[3]);

    //한번만 등장하는 몬스터 제외
    for(int i=1; i>=0; i--) {
        if(encounterBit[i]==0) {
            rate[i+1]+=rate[i+2];
            rate[i+2]=0;
        }        
    }

    random_device rd;
    mt19937 gen(rd());
    
    uniform_int_distribution<int> typeDis(1, 100);
    
    int level=typeDis(gen);
    int monsterType;
    for(int i=0; i<4; i++) {
        if(rate[i]>level) {
            monsterType=i;
            break;
        }
        level-=rate[i];
    }
    monsterLevel=monsterType;

    uniform_int_distribution<int> monsterDis(0, monsters[monsterType].size()-1);
    int monsterIndex=monsterDis(gen);
    int encounterMonsterBit=1<<monsterIndex;
    encounterBit[monsterType-2]-=encounterMonsterBit;
    return monsters[monsterType][monsterIndex];
}

void Manager::battle(Character& character) {
    int monsterLevel;
    Monster enemy=generate_enemy(monsterLevel);
    const string levelMent[4]={"약해 보이는", "강해 보이는", "믿을 수 없을 만큼 강해 보이는", "이길 수 없는"};

    cout << "\x1B[2J\x1B[H";
    cout<<"당신은 별의 더욱 깊숙한 곳으로 걸음을 옮겼다"<<endl;
    manager::get_enter();
    cout<<"당신은 그곳에서 "+levelMent[monsterLevel]+" 적과 마주쳤다!!"<<endl;
    manager::get_enter();
    
    while(true) {
        while(true) {
            show_status(character, enemy);
            int selection=character.choose_action(enemy);
            if(selection!=0)
                break;
            cout << "\x1B[2J\x1B[H";
        }

        show_status(character, enemy);
        if(enemy.is_dead()) {
            cin.ignore();
            cout<<"승리하였습니다. 능력치가 강화됩니다"<<endl;
            character.acquire_stat(enemy.get_stat());
            int& money=character.get_money();
            money+=100;
            cout<<100<<"코인을 획득하였습니다"<<endl;
            
            manager::get_enter();
            break;
        }
        
        character.attacked(enemy);
        show_status(character, enemy);
        if(character.is_dead()) {
            cout<<"패배하였습니다."<<endl;
            manager::get_enter();
            cout<<"..."<<endl;
            manager::get_enter();
            cout<<"..."<<endl;
            manager::get_enter();
            cout<<"으아악...!!!"<<endl;
            manager::get_enter();
            cout<<"뭐...뭐야 꿈이었구나..."<<endl;
            manager::get_enter();
            cout<<"End"<<endl;
            break;
        }
    }        
    scenarioIndex++;
}

void Manager::normal_event(Character& character) {    
    vector<Event*> events;
    Event* event=new Koh();
    events.push_back(event);
    events[0]->event_start(character);
    scenarioIndex++;
}

void Manager::show_status(const Character& character, const Monster& enemy) const {
    cout << "\x1B[2J\x1B[H";
    cout<<"Chapter "<<chapterIndex<<endl;
    cout<<"Scenario: #"<<scenarioIndex<<endl<<endl;
    enemy.show_status();
    cout<<endl;
    character.show_status();
    cout<<endl;
}

bool Manager::is_clear() {
    const int scenarioStandard[10]={0, 20};
    return scenarioIndex>=scenarioStandard[chapterIndex];
}