//
// Created by patrycja on 07.03.17.
//

#include "Polybius.h"
#include <sstream>
using namespace std;
string PolybiusCrypt(string message)
{
    char array[5][5]=
            {{'a', 'b', 'c', 'd', 'e'},
             {'f', 'g', 'h', 'i', 'k'},
             {'l', 'm', 'n', 'o', 'p'},
             {'q', 'r', 's', 't', 'u'},
             {'v', 'w', 'x', 'y', 'z'}};
    string encryptedMessage="";
    unsigned long int length=message.length();
    if (message.length()>0)
    {
        for (int i=0;i<length;i++) {
            int ascii;
            ascii=message[i];
            if(ascii>64 and ascii<91)
            {
                ascii+=32;
                message[i]=ascii;
            }
            int row = -1;
            int column = -1;
            if (message[i]=='j') {
                row=2;
                column=4;
            }
            else {
                for (int rows = 0; rows < 5 and row < 0 and column < 0; rows++) {
                    for (int columns = 0; columns < 5; columns++) {
                        if (message[i] == array[rows][columns]) {
                            row = rows + 1;
                            column = columns + 1;
                            break;
                        }
                    }
                }
            }
            if (row!=-1 or column!=-1) {
                ostringstream ss;
                ss << row;
                string str = ss.str();
                //encryptedMessage += str;
                ss << column;
                str = ss.str();
                encryptedMessage += str;
            }
        }
        cout << "Wiadomosc: " << message << endl;
        cout << "Wiadomosc zaszyfrowana" << encryptedMessage << endl;
        return encryptedMessage;
    }
}
string PolybiusDecrypt(string crypted)
{
    cout << crypted << "\n";
    char array[5][5]=
            {{'a', 'b', 'c', 'd', 'e'},
             {'f', 'g', 'h', 'i', 'k'},
             {'l', 'm', 'n', 'o', 'p'},
             {'q', 'r', 's', 't', 'u'},
             {'v', 'w', 'x', 'y', 'z'}};
    string message="";
    unsigned long int length=crypted.length()-1;
    int row=-1;
    int column=-1;
    int i=0,j=1;
    while (i<length) {
        row=crypted[i]-49;
        cout << crypted[i] <<"\n";
        column=crypted[j]-49;
        cout << crypted[j] <<"\n";
        message+=array[row][column];
        i+=2;
        j+=2;
    }
    cout << message;
    return message;
}