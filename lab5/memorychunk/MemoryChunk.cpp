//
// Created by bruzpatr on 28.03.17.
//

#include "MemoryChunk.h"
using namespace memorychunk;
MemoryChunk::MemoryChunk(size_t sz) {
    this->memorySize=sz;
    int8_t *beginPtr;
    if (this->memorySize>0)
        beginPtr = new int8_t[memorySize/sizeof(int8_t)];
    else
        beginPtr=nullptr;
    this->begin=beginPtr;
}
int8_t *MemoryChunk::MemoryAt(size_t offset) const {
    int8_t *offsetPtr;
    if (this->memorySize>0 and (this->memorySize-offset*sizeof(int8_t)))
        offsetPtr = this->begin+offset*sizeof(int8_t);
    else
        offsetPtr=nullptr;
    return offsetPtr;
}
size_t MemoryChunk::ChunkSize() const {
    if (this->begin!=nullptr)
        return memorySize;
    else
        return 0;
}
MemoryChunk::~MemoryChunk() {
    delete[] this->begin;
}