//
// Created by patrycja on 22.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <string>
#include <unordered_map>
#include <iostream>
#include <regex>

namespace nets {
    class View {
    private:
        std::string text;
    public:
        View(std::string text);

        std::string Render(const std::unordered_map<std::string, std::string> &model) const;

    };

}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
