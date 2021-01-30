#include<iostream>
#include<filesystem>
#include<chrono>
#include<thread>
#include<unordered_map>
#include<string>
#include<functional>
#include <fstream>
using namespace std;

#ifndef parser_H
#define parser_H


class parser{
public:
    parser(string address);
    void print();
    void save_file();
    void basic_info();

protected:
    string address;
    string author="";
    string type="";
    string name="";
    ifstream file;
    ofstream out;
};

#endif