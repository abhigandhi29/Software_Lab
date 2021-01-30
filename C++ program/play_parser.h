#include<iostream>
#include<filesystem>
#include<chrono>
#include<thread>
#include<unordered_map>
#include<string>
#include<functional>
using namespace std;
#include "parser.h"

#ifndef play_parser_H
#define ply_parser_H


class play_parser : public parser{
public:
    play_parser(string address,string type);
};

#endif