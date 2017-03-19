//
// Created by bodzbarb on 14.03.17.
//


#include <TinyUrl.h>
namespace tinyurl {
    std::unique_ptr<TinyUrlCodec> Init() {
        std::unique_ptr<TinyUrlCodec> p=std::make_unique<TinyUrlCodec>();
//        for(int i=0;i<6;i++)
//            p->current_hash[i]='0';
//        std::cout << "aaaa\n" << p->current_hash[5];
        return p;
    }
    void NextHash(std::array<char, 6> *state) {
        int ascii;
        for (int i = 5; i >= 0; i--) {
            if (i == 5 or (*state)[i + 1] == '0') {
                ascii = (*state)[i];
                ascii += 1;
                if (ascii == 58)
                    ascii = 65;
                else if (ascii == 91)
                    ascii = 97;
                else if (ascii == 123)
                    ascii = 48;
                (*state)[i] = ascii;
            }
            else
                break;
        }
    }
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
        for(int i=0;i<6;i++)
            (*codec)->current_hash[i]='0';
        std::cout << "aaaa\n" << (*codec)->current_hash[5];
        //NextHash(&(*codec)->current_hash);
        //std::cout << (*codec)->current_hash[0];
        //m.emplace("d", "ddd");
        (*codec)->url_map.emplace(url,(*codec)->current_hash);
        //(*codec)->url_map->emplace=(*codec)->current_hash;
        std::string encoded="";
        for (int i=0;i<6;i++) {
            encoded+=(*codec)->current_hash[i];
        }
        return encoded;

    }
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
        std::map<std::string, std::array<char, 6>>::iterator it;
        it = codec->url_map.find(hash);
        return it->first;
    }
}
//    {
//        int ascii=0;
//        int numberOfField;
//        int counter=0;
//        int last=0;
//        for (numberOfField=5;numberOfField>-1;numberOfField--) {
//            counter=0;
//            for (auto v : *state) {
//                if (counter == numberOfField and last == 0) {
//                    ascii = v;
//                    ascii++;
//                    if (ascii == 58)
//                        ascii = 65;
//                    else if (ascii == 91)
//                        ascii = 97;
//                    else if (ascii == 123)
//                        ascii = 48;
//                    (*state)[counter] = ascii;
//                    last = ascii;
//                }
//                counter++;
//            }
//        }
//    }

//std::unique_ptr<TinyUrlCodec> Init();

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
