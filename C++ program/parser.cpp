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

parser::parser(string address,string type1) : address{address},type{type1}{
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

parser::parser(const parser &p){
    address=p.address;
    name=p.name;
    author=p.author;
    type=p.type;
    language=p.language;
    file.open(address.c_str());
    out.open("index.txt",fstream::app);
}

parser::parser(string address,string name,string author,string type,string language){
    this->address=address;
    this->name=name;
    this->author=author;
    this->type=type;
    this->language=language;
    file.open(address.c_str());
    out.open("index.txt",fstream::app);    
}

void parser::basic_info(){
    file.clear();
    file.seekg(0, ios::beg);
    string mytext;
    while(getline (file,mytext)){
        istringstream iss(mytext);
        
        string s;
        iss >> s;
        if(s.compare("Title:")==0){
           while(iss>>s){
               //iss>>s;
               name.append(s);
               name.append(" ");
           }
       } 
       if(s.compare("Author:")==0){
            while(iss>>s){
               //iss>>s;
               //cout<<s<<endl;
               author.append(s);
               author.append(" ");
            }
        }
        if(s.compare("Language:")==0){
            while(iss>>s){
               //iss>>s;
               language.append(s);
               language.append(" ");
            }
        }   
    }
}

void parser::save_file(){
   
    out << "Type: "<<type<<"Author: "<<author<<"Name: "<<name<<endl;
}

void parser::print_as_list(){
    cout << ", Type: "<<type<<", Author: "<<author<<", Name: "<<name<<endl;
}

void parser::print(){
    cout<<"Book is of type "<<type<<endl;
    cout<<"Author if the book is "<<author<<endl;
    cout<<"Name of the book is "<<name<<endl;
    cout<<"Language of the book is "<<language<<endl;
    cout<<"Book is available at "<<address<<endl;
}


void parser::print_book(){
    file.clear();
    file.seekg(0, ios::beg);
    string mytext;
    int x=0;
    while(getline(file,mytext)){
        x++;
        cout<<mytext<<endl;
        if(x%20==0){
            cin.get();
        }
    }
}
