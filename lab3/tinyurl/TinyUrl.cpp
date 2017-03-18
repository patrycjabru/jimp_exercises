//
// Created by bodzbarb on 14.03.17.
//

#include <TinyUrl.h>
//std::unique_ptr<TinyUrlCodec> Init();

void NextHash(std::array<char, 6> *state)
{
    int ascii;

    for(int i=4;i>=0;i++)
    {
        if(i==5 or state[i+1]=='0')
        {
            ascii=state[i];
            ascii+=1;
            if(ascii==58)
                ascii=65;
            else if(ascii==91)
                ascii=97;
            else if(ascii==123)
                ascii=48;
            state[i]=ascii;
        }
    }
}
//std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
//std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);