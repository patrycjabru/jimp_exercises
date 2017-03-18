//
// Created by bodzbarb on 14.03.17.
//


//Jakis blad wywala jak probuje testy uruchomic i nie wiem o co chodzi T.T
//Zrobilam tak, zeby przechodzil tablice kilka razy od poczatku, bo nie wiem jak zrobic od konca.
//Ale nie sprawdzilam czy dziala, bo nie moge testu odpalic.

#include <TinyUrl.h>


namespace tinyurl {
    std::unique_ptr<TinyUrlCodec> Init()
    {
        std::unique_ptr<TinyUrlCodec> p=std::make_unique<TinyUrlCodec>();
        return p;
    }
    void NextHash(std::array<char, 6> *state)
    {
        int ascii=0;
        int numberOfField;
        int counter=0;
        int last=0;
        for (numberOfField=5;numberOfField>-1;numberOfField--) {
            counter=0;
            for (auto v : *state) {
                if (counter == numberOfField and last == 0) {
                    ascii = v;
                    ascii++;
                    if (ascii == 58)
                        ascii = 65;
                    else if (ascii == 91)
                        ascii = 97;
                    else if (ascii == 123)
                        ascii = 48;
                    v = ascii;
                    last = ascii;
                }
                counter++;
            }
        }
    }
};



//void NextHash(std::array<char, 6> *state)
//{
//    int ascii;
//
//    for(int i=4;i>=0;i++)
//    {
//         if(i==5 or &state[i+1]=='0')
//        {
//            ascii=state[i];
//            ascii+=1;
//            if(ascii==58)
//                ascii=65;
//            else if(ascii==91)
//                ascii=97;
//            else if(ascii==123)
//                ascii=48;
//            state[i]=ascii;
//        }
//    }
//    int ascii;
//    int counter=5;
//    int last=0;
//    for (auto v : state) {
//        if (counter==5 or (counter>-1 and last==48) {
//            ascii=state;
//            ascii++;
//            if (ascii==58)
//                ascii=65;
//            else if (ascii==91)
//                ascii=97;
//            else if (ascii==123)
//                ascii=48;
//            state=ascii;
//            last=ascii;
//            counter--;
//        }
//    }
//    int ascii;
//    for (auto v = std::array::end();v!=std::array::begin();) {
//
//        }
//
//    }
//    int ascii;
//    int numberOfField=5;
//    int counter=0;
//    int last=0;
//    for(auto v : *state) {
//        if (counter==numberOfField and last==0) {
//            ascii = v;
//            ascii++;
//            if (ascii == 58)
//                ascii = 65;
//            else if (ascii == 91)
//                ascii = 97;
//            else if (ascii == 123)
//                ascii = 48;
//            v = ascii;
//            last = ascii;
//        }
//        counter++;
//
//
//    }
//}
std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);