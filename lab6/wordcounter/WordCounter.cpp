//
// Created by patrycja on 08.04.17.
//

#include "WordCounter.h"
#include <utility>
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;
using namespace datastructures;
Word::Word(std::string newWord) {
    word=newWord;
}
bool Word::operator<(Word w) const{
    return this->word < w.word;
}
bool Word::operator==(Word w) const {
    return this->word == w.word;
}


Counts::Counts(int newCounts) {
    counts=newCounts;
}
Counts & Counts::operator++() {
    ++counts;
    return *this;
}
bool Counts::operator==(Counts c) const{
    return this->counts == c.counts;
}
bool Counts::operator<(Counts c) const{
    return this->counts < c.counts;
}
bool Counts::operator>(Counts c) const{
    return this->counts > c.counts;
}


WordCounter::WordCounter(std::string path) {
    ifstream file(path);
    std::string word;
    if(!file)
        cout << "Nie można otworzyć pliku!" << endl;
    while (file >> word)
    {
        bool found=false;
        for(int i=0;i<list.size();i++) {
            if (list[i].first.word==word) {
                ++list[i].second;
                found=true;
                break;
            }
        }
        if (!found) {
            Word newWord(word);
            Counts newCounts(1);
            pair<Word,Counts> a;
            a = std::make_pair(newWord, newCounts);
            list.emplace_back(a);
        }
    }
    file.close();
}
WordCounter::WordCounter(const std::initializer_list<Word> l) {
    bool found;
    for (auto word : l) {
        found = false;
        for (int i=0;i<list.size();i++) {
            if (list[i].first.word==word.word) {
                found=true;
                ++list[i].second;
                break;
            }
        }
        if (!found) {
            Counts newCounts(1);
            pair<Word,Counts> a;
            a = std::make_pair(word, newCounts);
            list.emplace_back(a);
        }
    }
}
int WordCounter::operator[](string key) {
    for(auto it : list) {
        if (it.first.word==key) {
            return it.second.counts;
        }
    }
    return 0;
}
unsigned long WordCounter::DistinctWords() {
    return list.size();
}
unsigned long WordCounter::TotalWords() {
    unsigned long total=0;
    for (auto l:list) {
        total+=l.second.counts;
    }
    return total;
}
set<Word> WordCounter::Words() {
    set<Word> output;
    for (int i = 0; i < list.size(); i++) {
        output.emplace(list[i].first);
    }
    return output;
}