#ifndef __READER_H__
#define __READER_H__

#include <iostream>

using namespace std;

class Reader {
private:
    string address;
public:
    Reader();
    Reader(string address_);
    void read();
};

#endif