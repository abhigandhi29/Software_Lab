#include<iostream>
#include<filesystem>
#include<chrono>
#include<thread>
#include<unordered_map>
#include<string>
#include<functional>
using namespace std;
#include "novel_parser.h"
#include<fstream>
#include<sstream>
#include<vector>

novel_parser::novel_parser(string address,string type) : parser(address,type){
}
novel_parser::novel_parser(const novel_parser &v) : parser(v){
}



void novel_parser::word_serch_chapter(string w){
    string mytext;
    vector<pair<int,pair<string,string>>> count;
    while(getline (file,mytext)){
        istringstream iss(mytext);
        bool start=false;
        string s;
        iss >> s;
        if(s.compare("CHAPTER")==0){
            start=true;
        }
        if(start){
            int c=0;
            string chapter_name="";
            string text="";
            while(iss){
                iss>>s;
                chapter_name.append(s);
                chapter_name.append(" ");
            }
            while(getline (file,mytext)){
                istringstream iss(mytext);
                string s;
                while(iss){
                    iss >> s;
                    if(s.compare("CHAPTER")){
                        count.push_back(make_pair(c,make_pair(chapter_name,text)));
                        iss>>s;
                        chapter_name="";
                        text="";
                        while(iss){
                            iss>>s;
                            chapter_name.append(s);
                            chapter_name.append(" ");
                        }
                        c=0;
                    }
                    if(s.compare(w)){
                        c++;
                    }
                    
                }
                text.append(mytext);
                text.append("\n");
            }
            
        }
    }
    sort(count.begin(), count.end());
    int n=5;
    if(count.size()<5){
        n=count.size();
    }
    for(int i=0;i<n;i++){
        if(count[i].first==0){
            cout<<"only"<<i+1<<"paragraphs contain word "<<w;
            return;
        }
        istringstream iss(count[i].second.second);
        cout<<count[i].second.first<<endl<<endl;
        string s;
        int a=0;
        while(iss){
            a++;
            iss>>s;
            cout<<s<<" ";
            if(a%20==0){
                cin.get();
            }
        }
    }
    
}


void novel_parser::word_serch_paragraph(string w){
    string mytext;
    vector<pair<int,string>> count;
    while(getline (file,mytext)){
        istringstream iss(mytext);
        string s;
        int c=0;
        while(iss){
            iss >> s;
            if(w.compare(s)==0){
                c++;
            }
        }
        count.push_back(make_pair(c,mytext));
    }
    sort(count.begin(), count.end());
    int n=5;
    if(count.size()<5){
        n=count.size();
    }
    for(int i=0;i<n;i++){
        if(count[i].first==0){
            cout<<"only"<<i+1<<"paragraphs contain word "<<w;
            return;
        }
        istringstream iss(count[i].second);
        //cout<<count[i].second.first<<endl<<endl;
        string s;
        int a=0;
        while(iss){
            a++;
            iss>>s;
            cout<<s<<" ";
            if(a%20==0){
                cin.get();
            }
        }
        cout<<endl<<count[i].first<<endl;
    }
    
}