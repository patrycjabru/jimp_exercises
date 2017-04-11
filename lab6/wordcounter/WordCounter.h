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
        bool operator<(Word w) const;
        bool operator==(Word w) const;
    };
    class Counts {
    private:
    public:
        int counts=0;
        Counts() = default;
        Counts(int newCounts);
        Counts &operator++();
        bool operator==(Counts c) const;
        bool operator<(Counts c) const;
        bool operator>(Counts c) const;
    };
    class WordCounter {
    public:
        std::vector<std::pair<Word,Counts>> list;
        WordCounter(std::string path);
        WordCounter()= default;
        WordCounter(const std::initializer_list<Word> l);
        int operator[](std::string key);
        unsigned long DistinctWords();
        unsigned long TotalWords();
        std::set<Word> Words();

    };

}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
