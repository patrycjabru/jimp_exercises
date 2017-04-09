//
// Created by patrycja on 08.04.17.
//
#include <WordCounter.h>
using namespace datastructures;
using namespace std;
int main () {
//    WordCounter c("/home/patrycja/CLion/exercises/lab1/exercises_aaa/lab6/wordcounter/test");
//    for (auto l : c.list) {
//        cout << l.first.word << " " << l.second.counts << "\n";
//    }
    WordCounter counter {Word("a"), Word("p"), Word("a"), Word("a")};
    for (auto l : counter.list) {
        cout << l.first.word << " " << l.second.counts << "\n";
    }
    cout << counter["a"] << endl;
    cout << counter.DistinctWords() << endl;
    cout << counter.TotalWords() << endl;
    return 0;
}