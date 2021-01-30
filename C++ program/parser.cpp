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

parser::parser(string address,string type) : address{address},type{type}{
    file.open(address.c_str());
    out.open("index.txt",fstream::app);
    if(file.is_open()){
        basic_info();
    }
    else{
        cout<<"error_opening the file"<<endl;
    }
    save_file();
}
void parser::basic_info(){
    string mytext;
    while(getline (file,mytext)){
        istringstream iss(mytext);
        
        string s;
        iss >> s;
        if(s.compare("Title:")==0){
           while(iss){
               iss>>s;
                name.append(s);
               name.append(" ");
           }
       } 
       if(s.compare("Author:")==0){
            while(iss){
               iss>>s;
               author.append(s);
               author.append(" ");
            }
        }
        if(s.compare("Language:")==0){
            while(iss){
               iss>>s;
               language.append(s);
               language.append(" ");
            }
        }
        
    }
}

void parser::save_file(){
    cout << "Type: "<<type<<"Author: "<<author<<"Name: "<<name<<endl;
    out << "Type: "<<type<<"Author: "<<author<<"Name: "<<name<<endl;
}

void parser::print(){
    cout<<"Type is "<<type<<endl;
    cout<<"Author is "<<author<<endl;
    cout<<"Name is "<<name<<endl;
}