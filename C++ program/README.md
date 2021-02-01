# LSM System

## Functionality

Automatically detects any need book added to Tracked Folder or any Subfolder

We can search for a book using Author name or Book name and print them.

We can print basic information of all available books

We can perform special operation on books depending on type of book

## How to run

### Option 1

```bash
#using Cmake
sudo apt install cmake
cd build
cmake ..
make
#and to run the program type
./LSM
#Since we are in build folder to track original folder type Location ./../
```

### Option 2

```bash
#Compile the program using
g++ -std=c++17 file_watcher.cpp main.cpp -pthread novel_parser.cpp parser.cpp play_parser.cpp
#and Run it using
./a.out
```

