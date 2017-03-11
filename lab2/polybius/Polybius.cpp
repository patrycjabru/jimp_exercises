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
    unsigned long int lenght=message.length()-1;
    if (message.length()>0)
    {
        for (int i=0;i<lenght;i++) {
            int row = -1;
            int column = -1;
            for (int rows = 0; rows < 5 and row < 0 and column < 0; rows++) {
                for (int columns = 0; columns < 5; columns++) {
                    if (message[i] == array[rows][columns]) {
                        row = rows+1;
                        column = columns+1;
                        break;
                    }
                }
            }

            ostringstream ss;
            ss << row;
            string str = ss.str();
            encryptedMessage += str;
            ss << column;
            str = ss.str();
            encryptedMessage += str;
        }
        cout << "Wiadomosc: " << message << endl;
        cout << "Wiadomosc zaszyfrowana" << encryptedMessage << endl;
        return encryptedMessage;
    }
}
string PolybiusDecrypt(string crypted)
{

}