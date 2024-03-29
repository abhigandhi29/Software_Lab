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
    parser(string address,string type1);
    parser(const parser &p);
    parser(string address,string name,string author,string type,string language);
    void print();
    void save_file();
    void basic_info();
    void print_as_list();
    void print_book();
    string author="";
    string type;
    string name="";

protected:
    string address;
    string language= "";
    ifstream file;
    fstream out;
};

#endif