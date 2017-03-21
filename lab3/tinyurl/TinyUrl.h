//
// Created by bodzbarb on 14.03.17.
//
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <iostream>
#include <map>

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H
namespace tinyurl {
    struct TinyUrlCodec {
        std::map<std::string, std::array<char, 6>> url_map;
        std::array<char, 6> current_hash;
    };

    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}

#endif //JIMP_EXERCISES_TINYURL_H
