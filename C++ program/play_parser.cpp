#include<iostream>
#include<filesystem>
#include<chrono>
#include<thread>
#include<unordered_map>
#include<string>
#include<functional>
#include "play_parser.h"
#include<fstream>
#include<sstream>
#include<set>
#include <algorithm>
using namespace std;

play_parser::play_parser(string address,string type1) : parser(address,type1){
    //cout<<address<<endl;
    //file.open(address.c_str());
}
play_parser::play_parser(const play_parser &p) : parser(p.address,p.name,p.author,p.type,p.language){
}

void play_parser::word_serch(string w){
    transform(w.begin(), w.end(), w.begin(), ::toupper);
    string mytext;
    set<string> final;
    file.clear();
    file.seekg(0, ios::beg);
    //cout<<"hereee"<<endl;
    while(getline (file,mytext)){
        istringstream iss(mytext);
        bool start=false;
        string s;
        iss >> s;
        //std::cout<<s<<endl;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if(s.compare("ACT")==0){
            start=true;
        }
        if(start){
            int c=0;
            set<string> names;
            while(getline (file,mytext)){
                istringstream iss(mytext);
                iss>>s;
                //cout<<s<<endl;
                if(s.compare("ACT")==0){
                    //cout<<"here"<<endl;
                    if(names.count(w)==1){
                        for(auto it:names){
                            final.insert(it);
                            //cout<<it<<endl;
                        }
                    }
                    names.clear();
                }
                //cout<<s<<" "<<s.length()<<endl;
                if(s.back()=='.'){
                    //cout<<s<<endl;
                    s.pop_back();
                    if(std::all_of( s.begin(), s.end(), &::isupper ))
                        names.insert(s);
                }    
            }
            if(names.count(w)==1){
                for(auto it:names){
                    final.insert(it);
                    //cout<<it<<endl;
                }
            }
        }  

    }
    cout<<"Character in same Act as "<<w<<" are ";
    for(auto it:final){
        if(it != *final.crbegin())
            cout<<it<<", ";
        else
            cout<<it<<"."<<endl;
    }
    cout<<endl;
}

        
