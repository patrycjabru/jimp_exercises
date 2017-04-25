//
// Created by patrycja on 31.03.17.
//

#include <iostream>
#include "TextPool.h"
using namespace pool;
TextPool::TextPool(const std::initializer_list<std::string> list) {
    for(auto &it : list)
        pool.insert(it);
}
TextPool::TextPool(TextPool &&p) {
    swap(this->pool, p.pool);
}
TextPool &TextPool::operator=(TextPool &&p) {
    if (this != &p)
        std::swap(this->pool, p.pool);
    return *this;
}
TextPool::~TextPool() {
    pool.clear();
}
std::experimental::string_view TextPool::Intern(const std::string &str) {
    auto wsk=pool.insert(str).first;
    return *wsk;
}

size_t TextPool::StoredStringCount() const {
    return pool.size();
}
