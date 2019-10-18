#include <iostream>
#include <string>
#include <vector>
#include "Speller.h"
#include <fstream>
#include <streambuf>
#include <chrono>
#include <windows.h>
#include <iomanip>

using namespace std;

int main(){

linearSpeller myLinearSpeller;
setSpeller mySetSpeller;
hashTableSpeller myHashTableSpeller;
trieSpeller myTrieSpeller;

fstream file;
string word, filename;
filename = "C:\\Users\\HP\\Desktop\\AdvancedAlg\\Spellbook\\vocab.txt";
file.open(filename.c_str());

while (file >> word){
    mySetSpeller.insertWord(word);
    myHashTableSpeller.insertWord(word);
    myTrieSpeller.insertWord(word);
    myLinearSpeller.insertWord(word);
}

double freq = 0.0;
    LARGE_INTEGER x;
    QueryPerformanceFrequency(&x);
    freq = x.QuadPart/1000.0;


QueryPerformanceCounter(&x);
std::int64_t start = x.QuadPart;
cout<<myTrieSpeller.findWord("Word");
QueryPerformanceCounter(&x);
std::int64_t End = x.QuadPart;
std::int64_t taken = End - start;
cout<<"Trie:"<< std::setw(8) << std::fixed << " " << " " <<taken / freq<< std::endl;

}
