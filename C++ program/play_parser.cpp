#include<iostream>
#include<filesystem>
#include<chrono>
#include<thread>
#include<unordered_map>
#include<string>
#include<functional>
using namespace std;
#include "play_parser.h"
#include<fstream>
#include<sstream>
#include<set>

play_parser::play_parser(string address,string type1) : parser(address,type1){
}
play_parser::play_parser(const play_parser &s) : parser(s){
}

void play_parser::word_serch(string w){
    string mytext;
    set<string> final;
    while(getline (file,mytext)){
        istringstream iss(mytext);
        bool start=false;
        string s;
        iss >> s;
        if(s.compare("ACT")==0){
            start=true;
        }
        if(start){
            int c=0;
            set<string> names;
            while(getline (file,mytext)){
                iss>>s;
                if(s.compare("ACT")==0){
                    if(names.count(w)==1){
                        for(auto it:names){
                            final.insert(it);
                        }
                    }
                }
                if(s[-1]=='.'){
                    s.pop_back();
                    names.insert(s);
                }    
            }
        }  

    }
    cout<<"Character in same Act as "<<w<<" are ";
    for(auto it:final){
        cout<<it<<", ";
    }
    cout<<endl;
}

        
