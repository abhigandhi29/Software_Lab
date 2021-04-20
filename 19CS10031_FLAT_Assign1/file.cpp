#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class NFA{
    public:
    uint32_t n,m;
    
    void readNFA(string file){
        ifstream Myfile(file);
        string line;
        while(getline(Myfile,line)){
            stringstream  lineStream(line);
            int value;
            while(lineStream >> value){

            }
        }

    }
};