#include<iostream>
#include<filesystem>
#include<chrono>
#include<thread>
#include<string>
#include<functional>
#include<vector>
using namespace std;
#include "file_watcher.h"
#include "parser.h"
#include "play_parser.h"
#include "novel_parser.h"
#include<set>
#include<variant>

vector<play_parser> play;
vector<novel_parser> novel;
bool scan_for_cmd=false;


//This function is called in seprate tread.
//It continuously calls start function in filewatcher which checks for any new file
void create_reader(string loc){
    vector<pair<string,FileStatus>> status; 
    FileWatcher fw{loc};
    while(true){
        fw.start(status);
        if(status.size()==0){
            scan_for_cmd=true;
        }
        else{
            scan_for_cmd=false;
        }
        // Process only regular files, all other file types are ignored
        for(auto it : status){
            if(it.first.find("/build/") != string::npos){
                continue;
            }
            if(it.first.find(".txt") == string::npos){
                cout<<it.first<<" is not a '.txt' file"<<endl;
                continue;            
            }
            

            switch(it.second) {
                case FileStatus::created:
                    cout<<endl;
                    std::cout << "New Book detected: " << it.first << endl;
                    cout<<"Type '0' for novel"<<endl<<"type 1 for play"<<endl;
                    cout<<"Enter 2 for Invalid '.txt' file"<<endl<<"If Nothing is printed enter number Twice"<<endl;
                    int type;
                    cin>>type;
                    if(type==0){
                        novel.push_back(novel_parser(it.first,"novel "));
                
                    }
                    else if(type==1){
                        play.push_back(play_parser(it.first,"play "));
                    }
                    else{
                        cout<<"invalid_type"<<endl;
                    }
                    break;
                case FileStatus::modified:
                    std::cout << "File modified: " << it.first << endl;
                    break;
                case FileStatus::erased:
                    std::cout << "File erased: " << it.first << endl;
                    break;
                default:
                    std::cout << "Error! Unknown file status." << endl;
            }
        }
    }
}

//prints basic information for serch
void printinstructionsforserch(){
    cout<<"Enter 1 for searching by Book name"<<endl;
    cout<<"Enter 2 for searching by Author name"<<endl;
}

//serch for books based on author or book name and returns a set of id containing all books matching serch word
set<int> serch_and_print(){
    set<int> serch_results;
    printinstructionsforserch();
    int d;
    cin>>d;
    if(d==1){
        cout<<"Enter Book Name: ";
        string name;
        cin>>name;
        transform(name.begin(), name.end(), name.begin(), ::toupper);
        int i=0;
        for(auto& it : play){
            string temp=it.name;
            transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            if(temp.find(name) != string::npos){
                cout<<"ID: "<<i;
                it.print_as_list();
                serch_results.insert(i);
            }
            i++;
        }
        for(auto& it : novel){
            string temp=it.name;
            transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            if(temp.find(name) != string::npos){
                cout<<"ID: "<<i;
                it.print_as_list();
                serch_results.insert(i);
            }
            i++;
        }
    }
    else if(d==2){
        cout<<"Enter author name: ";
        string name;
        cin>>name;
        transform(name.begin(), name.end(), name.begin(), ::toupper);
        int i=0;
        for(auto& it : play){
            string temp=it.author;
            transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            if(temp.find(name) != string::npos){
                cout<<"ID: "<<i;
                it.print_as_list();
                serch_results.insert(i);
            }
            i++;
        }     
        for(auto& it : novel){
            //cout<<it->name<<endl;
            string temp=it.author;
            transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            if(temp.find(name) != string::npos){
                cout<<"ID: "<<i;
                it.print_as_list();
                serch_results.insert(i);
            }
            i++;
        }           
    }
    return serch_results;
}

//prints main instructions i.e instructions for cin call in main
void printinstructions(){
    cout<<"Enter 3 for printing all books"<<endl;
    cout<<"Enter 4 for searching a book"<<endl;
    cout<<"Enter 5 for word search"<<endl;
}

//calls serch and print for geeting the set of all possible book
//perform special function on one of the chossen book
//Depending on the type of book
void word_serch(){
    set<int> serch_result=serch_and_print();
    cout<<"Enter ID of Book to select: "<<endl;
    cout<<"possible options are:";
    for(int x:serch_result){
        if(x!=*serch_result.cbegin())
            cout<<x<<", ";
        else
            cout<<x<<".";
    }
    cout<<endl;
    int id;
    cin>>id;
    if(id>=play.size()+novel.size() || id<0 || serch_result.count(id)==0){
        cout<<"Invalid ID"<<endl;
        return;
    }
    if(id>=play.size()){
        auto parser = novel[id-play.size()];
        if(parser.type.compare("novel ")==0){
            cout<<"Enter 1 for serching in paragraphs"<<endl;
            cout<<"Enter 2 for serching in chapter"<<endl;
            int c;
            cin>>c;
            string w;
            cout<<"Enter the word to serch:";
            cin>>w;
            if(c==1){
                parser.word_serch_paragraph(w);
            }
            else if(c==2){
                parser.word_serch_chapter(w);
            }

        }
    }
    else{
        auto parser = play[id];    
        if(parser.type.compare("play ")==0){
            //cout<<parser.type;
            cout<<"Enter the character to serch:";
            string w;
            cin>>w;
            //play_parser parser=parser;
            parser.word_serch(w);
        }
    }
}

int main() {
    string loc="./";
    cout<<"Enter Path to track relative to current location: './ for same location': ";
    cin>>loc;
    //creating new thread
    thread reader(create_reader,loc);
    int c;
    while(true){
        if(scan_for_cmd){
            std::this_thread::sleep_for(chrono::milliseconds(5000));
            printinstructions();
            cin>>c; 
            if(c==3){
                for(auto& it : novel){
                    cout<<endl;
                    it.print();
                    cout<<endl;
                }
                for(auto& it : play){
                    cout<<endl;
                    it.print();
                    cout<<endl;
                }
            }
            else if(c==4){
                set<int> s=serch_and_print();
                //prints whole book if user wants to print it in  a set of 30 lines.
                cout<<"Enter ID of book to print or else enter -1: ";
                int x;
                cin>>x;
                if(x!=-1){
                    if(x>=novel.size()+play.size() || x<0 || s.count(x)==0){
                        cout<<"Invalid ID"<<endl;
                        continue;
                    }
                    if(x>=play.size()){
                        novel[x-play.size()].print_book();
                    }
                    else{
                        play[x].print_book();
                    }
                }
            }
            else if(c==5){
                word_serch();   
            }
        }
    }
    reader.join();  
}
