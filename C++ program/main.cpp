#include<iostream>
#include<filesystem>
#include<chrono>
#include<thread>
#include<unordered_map>
#include<string>
#include<functional>
#include<vector>
using namespace std;
#include "file_watcher.h"

vector<string> add;

void create_reader(string loc){
    vector<pair<string,FileStatus>> status; 
    FileWatcher fw{loc};
    while(true){
        fw.start(status);
        
        // Process only regular files, all other file types are ignored
        for(auto it : status){
            if(!it.first.find(".txt")){
                cout<<it.first<<" is not a txt file"<<endl;
                continue;
            }
            //cout<<it.first<<endl;
            switch(it.second) {
                case FileStatus::created:
                    std::cout << "New Book detected: " << it.first << endl;
                    add.push_back(it.first);
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




int main() {
    string loc="./";
    thread reader(create_reader,loc);
    reader.join();
    
}