#include<iostream>
#include<string>
#include<functional>
using namespace std;
#include "novel_parser.h"
#include<fstream>
#include<sstream>
#include<vector>
#include <algorithm> 

//constructor: calls constructor of parser, parent class.
novel_parser::novel_parser(string address,string type) : parser(address,type){
}

//copy constructor
novel_parser::novel_parser(const novel_parser &p) : parser(p.address,p.name,p.author,p.type,p.language){
}

//serches for word chapter wise
void novel_parser::word_serch_chapter(string w){
    string mytext;
    transform(w.begin(), w.end(), w.begin(), ::toupper);

    file.clear();
    file.seekg(0, ios::beg);
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
            while(iss>>s){
                //iss>>s;
                chapter_name.append(s);
                chapter_name.append(" ");
            }
            while(getline (file,mytext)){
                istringstream iss(mytext);
                string s;
                while(iss>>s){
                    if(s.compare("CHAPTER")==0){
                        count.push_back(make_pair(c,make_pair(chapter_name,text)));
                        iss>>s;
                        chapter_name="";
                        text="";
                        while(iss>>s){
                            //iss>>s;
                            chapter_name.append(s);
                            chapter_name.append(" ");
                        }
                        c=0;
                    }
                    transform(s.begin(), s.end(), s.begin(), ::toupper);
                    if(s.find(w)!=string::npos){
                        c++;
                    }
                    
                }
                text.append(mytext);
                text.append("\n");
            }
            
        }
    }
    sort(count.begin(), count.end(),greater<pair<int,pair<string,string>>>());
    int n=5;
    if(count.size()<5){
        n=count.size();
    }
    for(int i=0;i<n;i++){
        if(count[i].first==0){
            if(i>0)
                cout<<"only "<<i<<" paragraphs contain word "<<w<<endl;
            else
                cout<<"No paragraph contain word "<<w<<endl;
            return;
        }
        istringstream iss(count[i].second.second);
        cout<<count[i].second.first<<": "<<count[i].first<<endl<<endl;
        string s;
        int a=0;
        while(iss>>s){
            a++;
            //iss>>s;
            cout<<s<<" ";
            if(a%55==0){
                cin.get();
            }
        }
        cout<<endl;
    }
    
}

//serches for word paragraph wise
void novel_parser::word_serch_paragraph(string w){
    string mytext;
    transform(w.begin(), w.end(), w.begin(), ::toupper);
    
    vector<pair<int,string>> count;
    while(getline (file,mytext)){
        stringstream ss;
        ss << mytext;
        ss << " ";
         while(mytext != "" ){
            std::getline( file , mytext );
            ss << mytext;
            ss << " ";
        }
        istringstream iss(ss.str());
        string s;
        int c=0;
        while(iss>>s){
            //iss >> s;
            transform(s.begin(), s.end(), s.begin(), ::toupper);
            if(s.find(w)!=string::npos){
                c++;
            }
        }
        count.push_back(make_pair(c,ss.str()));
    }
    sort(count.begin(), count.end(),greater<pair<int,string>>());
    int n=5;
    if(count.size()<5){
        n=count.size();
    }
    for(int i=0;i<n;i++){
        if(count[i].first==0){
            if(i>0)
                cout<<"only "<<i<<" paragraphs contain word "<<w<<endl;
            else   
                cout<<"No paragraph contain word "<<w<<endl;
            return;
        }
        istringstream iss(count[i].second);
        cout<<endl<<"Count: "<<count[i].first<<endl;
        string s;
        int a=0;
        while(iss>>s){
            a++;
            cout<<s<<" ";
            if(a%55==0){
                cin.get();
            }
        }
        
    }
    
}