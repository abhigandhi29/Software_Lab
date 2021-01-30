#include<iostream>
#include<filesystem>
#include<chrono>
#include<thread>
#include<unordered_map>
#include<string>
#include<functional>
using namespace std;
#include "novel_parser.h"

novel_parser::novel_parser(string address,string type) : parser(address){
    this->type=type;
}