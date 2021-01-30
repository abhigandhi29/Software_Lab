#include<iostream>
#include<filesystem>
#include<chrono>
#include<thread>
#include<unordered_map>
#include<string>
#include<functional>
using namespace std;
#include "parser.h"
#include<fstream>
#include<sstream>

parser::parser(string address) : address{address}{
    file.open(address.c_str());
    out.open("index.txt");
}
void parser::basic_info(){
    string mytext;
    while(getline (file,mytext)){
        istringstream iss(mytext);
        while(iss){
           string s;
           iss >> s;
           if(s.compare("Title:")){
               while(iss){
                   iss>>s;
                   name.append(s);
                   name.append(" ");
               }
           } 
           if(s.compare("Author:")){
               while(iss){
                   iss>>s;
                   name.append(s);
                   name.append(" ");
               }
           }
           if(s.compare("Title:")){
               while(iss){
                   iss>>s;
                   name.append(s);
                   name.append(" ");
               }
           }
        }
    }
}

void parser::save_file(){
    
}

void parser::print(){
    cout<<"Type is "<<type<<endl;
    cout<<"Author is "<<author<<endl;
    cout<<"Name is "<<name<<endl;
}