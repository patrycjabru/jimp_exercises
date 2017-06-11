//
// Created by moje konto on 2017-06-11.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template<class T, class U>
class SequentialIdGenerator {
public:
    SequentialIdGenerator() : first(true),counter_(0){}
    SequentialIdGenerator(U value) : first(true),counter_(value){}
    T NextValue(){
        if(!first){
            ++counter_;
        }
        first=false;
        return T(counter_);}
private:
    bool first;
    U counter_;
};

#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
