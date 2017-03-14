//
// Created by bodzbarb on 14.03.17.
//
#include <utility>
#include <string>
#include <array>
#include <memory>

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

//std::unique_ptr<TinyUrlCodec> Init();
void NextHash(std::array<char, 6> *state);
//std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
//std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);

#endif //JIMP_EXERCISES_TINYURL_H
