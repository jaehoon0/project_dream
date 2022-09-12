#include "reader.h"
#include <fstream>

Reader::Reader():address("") {}

Reader::Reader(string address_):address(address_) {};

void Reader::read() {
    cout << "\x1B[2J\x1B[H";
    cout<<"(---스토리를 진행하시려면 Enter를 눌러주세요---)"<<endl;
    ifstream scenario(address);

    char line[500];
    cin.ignore();
	while (scenario.getline(line, sizeof(line))) {
        char next='n';
		cout<<line<<endl;
        while(next!='\n')
            cin.get(next);
	}
}