//
// Created by patrycja on 31.03.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>
namespace pool {
    class TextPool {
    public:
        std::set<std::string> pool;
    public:
        TextPool() = default;
        TextPool(const std::initializer_list<std::string> list);
        TextPool(TextPool &&p);
        TextPool &operator=(TextPool &&p);
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;
    };
}
#endif //JIMP_EXERCISES_TEXTPOOL_H
