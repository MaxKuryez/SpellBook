#include "Speller.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

///Vector

bool linearSpeller::findWord(const string word){
    for(int i = 0; i < speller.size(); i++){
        if(speller[i].compare(word) == 0){
           return true;
           }
    }
    return false;
}

void linearSpeller::insertWord(const string word){
    speller.push_back(word);
}

///Set

void setSpeller::insertWord(const string word){
    speller.insert(word);
}

bool setSpeller::findWord(const string word){
    if(speller.find(word)!=speller.end()){
        return true;
    }else{
        return false;
}
}

///Hash table

void hashTableSpeller::insertWord(const string word){
    size_t myHash = 0;
    for (int i = 0; i < word.size(); i++){
        myHash = ((myHash*7)%900 + word[i])%900;
    }
    speller[myHash].push_back(word);
}

bool hashTableSpeller::findWord(const string word){
    size_t myHash = 0;
    for (int i = 0; i < word.size(); i++){
        myHash = ((myHash*7)%900 + word[i])%900;
    }
    for (int i = 0; i < speller[myHash].size(); i++){
        if (speller[myHash][i].compare(word) == 0){
            return true;
        }
    }
    return false;
}

hashTableSpeller::hashTableSpeller(){
    speller.resize(900);
}

void hashTableSpeller::getSize(){
    cout<<speller.size();
}

///Trie

void trieSpeller::insertWord(const string word){
    node *ptr = &root;
    int i = 0;
    while( i < word.length() ){
        if (!(ptr->letter)[word[i]])
            ptr->letter[word[i]]= new node;
        ptr = ptr -> letter[word[i]];
        i++;
    }
    ptr -> valid = true;
}

bool trieSpeller::findWord(const string word){
    node *ptr = &root;
    int i = 0;
    while( i < word.length()){
        if (!ptr -> letter[word[i]])
            return false;
        ptr = ptr -> letter[word[i]];
        i++;
    }
    return ptr -> valid;
}
