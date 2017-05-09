//
// Created by patrycja on 08.04.17.
//
#include <WordCounter.h>
using namespace datastructures;
using namespace std;
int main () {
    WordCounter counter {Word("a"), Word("p"), Word("a"), Word("a")};
    for (auto l : counter.list) {
        cout << l.first.word << " " << l.second.counts << "\n";
    }
    cout << counter["a"] << endl;
    cout << counter.DistinctWords() << endl;
    cout << counter.TotalWords() << endl;
    return 0;
}