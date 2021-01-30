#include<iostream>
#include<filesystem>
#include<chrono>
#include<thread>
#include<unordered_map>
#include<string>
#include<functional>
using namespace std;
#include "play_parser.h"

play_parser::play_parser(string address,string type) : parser(address,type){
}