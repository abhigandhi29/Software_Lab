#include<iostream>
#include<filesystem>
#include<chrono>
#include<thread>
#include<unordered_map>
#include<string>
#include<functional>
using namespace std;
#include "parser.h"

#ifndef novel_parser_H
#define novel_parser_H


class novel_parser : public parser{
public:
    novel_parser(string address,string type);
};

#endif