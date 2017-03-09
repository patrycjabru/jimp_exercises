//
// Created by patrycja on 07.03.17.
//

#include <iostream>
#include <Polybius.h>
#include <fstream>

using namespace std;
int main(string inputName, string outputName, bool isEncrypted) {
    ifstream inputFile(inputName);
/*    string word;
    string newWord;
    if(!inputFile)
        cout << "Nie można otworzyć pliku!" << endl;

    ofstream outputFile (outputName, ios_base::in | ios_base::app);
    if(!outputFile)
        cout << "Nie można otworzyć pliku!" << endl;

    while(inputFile >> word){
        if (isEncrypted==0)
            newWord=PolybiusCrypt(word);
            outputFile << newWord+" ";
    }
    inputFile.close();
    outputFile.close();*/
    return 0;
}