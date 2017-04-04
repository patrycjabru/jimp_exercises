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
        std::vector<std::string> pool;
    public:
        TextPool();
        TextPool(std::initializer_list<std::string> vec);

        //Rule of five://
        //1. konstruktor kopiujący
//        TextPool(const TextPool &xxx);
        //2. konstruktor przenoszący
//        TextPool(TextPool &&xxx);
        //3. operator przypisania kopiujący
//        TextPool &operator=(const TextPool &other);
//        {
//            if(this != &other)
//            {
//                //Do assignment logic.
//            }
//            return *this;
//        }
        //4. operator przypisania przenoszący
//        TextPool &operator=(TextPool &&xxx);
        //5. Destruktor
//        ~TextPool();
//        domyślny konstruktor
//        konstruktor z listą inicjalizacyjną
//        std::experimental::string_view Intern(const std::string &str);
//        size_t StoredStringCount() const;
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;
//        void append(std::initializer_list<std::string> l) {
//            pool.insert(v.end(), l.begin(), l.end());
    };
}
#endif //JIMP_EXERCISES_TEXTPOOL_H
