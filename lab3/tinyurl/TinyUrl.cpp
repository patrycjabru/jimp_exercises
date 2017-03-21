//
// Created by bodzbarb on 14.03.17.
//


#include <TinyUrl.h>
namespace tinyurl {
    std::unique_ptr<TinyUrlCodec> Init() {
        std::unique_ptr<TinyUrlCodec> p=std::make_unique<TinyUrlCodec>();
        for(int i=0;i<6;i++)
            p->current_hash[i]='0';
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
        NextHash(&(*codec)->current_hash);
        (*codec)->url_map.emplace(url,(*codec)->current_hash);
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
