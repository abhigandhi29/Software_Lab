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
    novel_parser(const novel_parser &v);
    void word_serch_chapter(string w);
    void word_serch_paragraph(string w);
};

#endif