//
// Created by patrycja on 22.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <string>
#include <unordered_map>
class View {
    std::string Render(const std::unordered_map <std::string, std::string> &model) const;
};
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
