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
    play_parser(string address,string type1);
    play_parser(const play_parser &p);
    void word_serch(string w);
    //string address;
//private:
    //ifstream file;
};

#endif