//
// Created by patrycja on 31.03.17.
//

#include "TextPool.h"
using namespace pool;
TextPool::TextPool() {}
TextPool::TextPool(std::initializer_list<std::string> list) {
    std::vector<std::string> vec;
    bool found;
    for( auto it = list.begin(); it != list.end(); ++it ) {
        found=0;
        for (auto v : vec) {
            if (v==*it) {
                found=1;
                break;
            }
        }
        if (found==0)
            vec.emplace(vec.begin(), *it);
    }
    pool=vec;
}
//1. konstruktor kopiujący
//TextPool::TextPool(const TextPool &xxx) {
//    size_t sz = strlen(xxx.name_);
//    name_ = new char[sz];
//    strcpy(name_,xxx.name_);
//}
//2. konstruktor przenoszący
//TextPool::TextPool(TextPool &&xxx);
//3. operator przypisania kopiujący
//TextPool & TextPool::*operator=(const TextPool &&other);
//4. operator przypisania przenoszący
//TextPool & TextPool::operator=(TextPool &&xxx);
//5. Destruktor
//TextPool::~TextPool();

std::experimental::string_view TextPool::Intern(const std::string &str) {
    std::experimental::string_view text=str;
    bool found;
    for (auto v : pool) {
        if (v==str) {
            found=1;
            text=v;
            break;
        }
    }
    if (found==0) {
        pool.emplace(pool.begin(), str);
        text=pool[0];
    }
    return text;
}

size_t TextPool::StoredStringCount() const {
    return pool.size();
}