#include<iostream>
#include<string>
#include<functional>
#include "play_parser.h"
#include<fstream>
#include<sstream>
#include<set>
#include <algorithm>
using namespace std;

//calls parser constructor
play_parser::play_parser(string address,string type1) : parser(address,type1){
}

//copy constructor
play_parser::play_parser(const play_parser &p) : parser(p.address,p.name,p.author,p.type,p.language){
}


//special feature function of play_type_class
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
                while(std::all_of( s.begin(), s.end(), &::isupper ) && s.back()!='.'){
                    string temp;
                    iss>>temp;
                    s.append(" ");
                    s.append(temp);
                    //cout<<s<<std::all_of( s.begin(), s.end(), &::isupper )<<endl;
                }
                if(s.back()=='.'){
                    s.pop_back();
                    string temp;
                    bool check=true;
                    istringstream it(s);
                    while(it>>temp){
                        if(!std::all_of( temp.begin(), temp.end(), &::isupper ))
                            check=false;
                
                    }
                    if(check){
                        names.insert(s);
                    }
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
    //prints all character stored in set final
    cout<<"Character in same Act as "<<w<<" are ";
    for(auto it:final){
        if(it != *final.crbegin())
            cout<<it<<", ";
        else
            cout<<it<<"."<<endl;
    }
    cout<<endl;
}

        
