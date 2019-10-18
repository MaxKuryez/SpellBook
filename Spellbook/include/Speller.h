#ifndef SPELLER_H
#define SPELLER_H
#include <vector>
#include <string>
#include <set>
#define NUMC 256

using namespace std;

class linearSpeller{
        vector<string> speller;
    public:
        void insertWord(const string word);
        bool findWord(const string word);
};

class setSpeller{
        set<string> speller;
    public:
        void insertWord(const string word);
        bool findWord(string word);
};

class hashTableSpeller{
        vector<vector<string>> speller;
public:
    hashTableSpeller();
    void insertWord(const string word);
    bool findWord(const string word);
    void getSize();
       };

class trieSpeller{
    struct node{
        node *letter[NUMC];
        bool valid;
        node(){valid = false; for(int i = 0; i < NUMC; i++) letter[i]= nullptr;}
       }
    root;
public:
    void insertWord(const string word);
    bool findWord(const string word);
       };

#endif // SPELLER_H
