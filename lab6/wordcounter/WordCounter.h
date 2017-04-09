//
// Created by patrycja on 08.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>

namespace datastructures {
    class Word {
    private:

    public:
        std::string word;
        Word(std::string newWord);
        Word()=default;
    };
    class Counts {
    private:

    public:
        int counts=0;
        Counts() = default;
        Counts(int newCounts);
        Counts &operator++();
    };
    class WordCounter {
    private:

//        std::map<Word,Counts> list;
    public:
        std::vector<std::pair<Word,Counts>> list;
//        std::list<std::pair<Word,Counts>> list;
        WordCounter(std::string path);
        WordCounter()= default;
        WordCounter(const std::initializer_list<Word> l);
        int operator[](std::string key);
        unsigned long DistinctWords();
        unsigned long TotalWords();
        std::set<Word> Words();
//        int Counts(int x);

    };

}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
