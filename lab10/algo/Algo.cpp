//
// Created by bodzbarb on 16.05.17.
//

#include "Algo.h"

namespace algo {
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        std::copy_n(v.begin(), n_elements, std::back_inserter(*out));
    }

    void InitializeWith(int initial_value, std::vector<int> *v) {
        std::fill(v->begin(), v->end(), initial_value);
//        std::iota(v->begin(), v->end(), initial_value);
    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        std::vector<int> vec{0};
        std::fill_n(vec.begin(), length, initial_value);
        return vec;
    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> s;
        std::transform(v.begin(), v.end(), s.begin(),
                       [](double c) { return std::to_string(c);});
        return s;
    }

    void RemoveDuplicatesInPlace(std::vector<std::string> *v) {
        std::unique(v->begin(), v->end());
    }

}