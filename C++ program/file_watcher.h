#include<iostream>
#include<filesystem>
#include<chrono>
#include<thread>
#include<unordered_map>
#include<string>
#include<functional>
using namespace std;

#ifndef FileWatcher_H
#define FileWatcher_H

enum class FileStatus {created, modified, erased};

class FileWatcher{
public:
    string path_to_watch;
    chrono::duration<int, std::milli> delay;
    FileWatcher(string path_to_watch="./", chrono::duration<int, std::milli> delay=chrono::milliseconds(5000));
    void start(vector<pair<string,FileStatus>> &status);

private:
    unordered_map<std::string, std::filesystem::file_time_type> files;
    bool running_ = true;
    bool contains(const std::string &key);
};

#endif