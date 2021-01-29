#include<iostream>
#include<filesystem>
#include<chrono>
#include<thread>
#include<unordered_map>
#include<string>
#include<functional>
using namespace std;
#include "file_watcher.h"

 // Define available file changes




    FileWatcher::FileWatcher(std::string path_to_watch, std::chrono::duration<int, std::milli> delay) : path_to_watch{path_to_watch}, delay{delay} {
        //for(auto &file : std::filesystem::recursive_directory_iterator(path_to_watch)) {
        //    paths_[file.path().string()] = std::filesystem::last_write_time(file);
        //}
    }
 
    void FileWatcher::start(vector<pair<string,FileStatus>> &status) {
        //while(running_) {
            // Wait for "delay" milliseconds
            std::this_thread::sleep_for(delay);
            status.clear();
            for (auto it = files.cbegin(); it != files.cend(); it++)  {
                if (!std::filesystem::exists(it->first)) {
                    status.push_back(make_pair(it->first,FileStatus::erased));
                    files.erase(it);
                
                }
            }
 
            // Check if a file was created or modified
            for(auto &file : std::filesystem::recursive_directory_iterator(path_to_watch)) {
                    auto current_file_last_write_time = std::filesystem::last_write_time(file);
 
                // File creation
                if(!contains(file.path().string())) {
                    files[file.path().string()] = current_file_last_write_time;
                    status.push_back(make_pair(file.path().string(),FileStatus::created));
                    cout<<"here"<<endl;
                 // File modification
                } else {
                    if(files[file.path().string()] != current_file_last_write_time) {
                        files[file.path().string()] = current_file_last_write_time;
                        status.push_back(make_pair(file.path().string(),FileStatus::modified));
                    }
                }
            }
        //}
    }
 
    // Check if "paths_" contains a given key
    // If your compiler supports C++20 use paths_.contains(key) instead of this function
    bool FileWatcher::contains(const std::string &key) {
        auto el = files.find(key);
        return el != files.end();
    }
 




