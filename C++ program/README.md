# LSM System

## Functionality

Automatically detects any need book added to Tracked Folder or any Subfolder

We can search for a book using Author name or Book name and print them.

We can print basic information of all available books

We can perform special operation on books depending on type of book

For Novel: 

1. Paragraph search: Search every paragraph for the given word and print top 5 paragraphs if exist.

                      2. Chapter search: Search every chapter for the given word and print top 5 paragraphs if exist.

For Play:

1. Print all characters present in a ACT along with given character.

## How to run

### Option 1

```bash
#using Cmake
#for installing cmake run
sudo apt install cmake
#for building
cd build 
cmake ..
make
#and to run the program type in build folder
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

