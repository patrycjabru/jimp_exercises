//
// Created by bodzbarb on 16.05.17.
//

#include "Algo.h"
#include <iostream>

int main() {
        std::vector<int> v {0,0,0,0};
        std::fill(v.begin(), v.end(), 77);
        for(int i=0;i<v.size();i++)
        {
                std::cout<<v[i]<<" ";
        }

        std::vector<std::string> vec{"l","j"};
        algo::RemoveDuplicatesInPlace(vec);

//        std::vector<int> vec{0};
//        std::fill_n(vec.begin(), 2, 77);
//        for(int i=0;i<vec.size();i++)
//        {
//                std::cout<<vec[i]<<" ";
//        }
        return 0;
};