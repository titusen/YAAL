#pragma once
#include <cstdlib>
#include <cstdint>
#include <memory>
#include <stack>
#include "ChunkAllocatorBase.hpp"

namespace yaal {

#ifndef YAAL_DEFAULT_CHUNK_SIZE
    #define YAAL_DEFAULT_CHUNK_SIZE 264
#endif
template <typename T>
class ChunkAllocator : public ChunkAllocatorBase<T>
{
public:
    using value_type = T;
    ChunkAllocator(const u_int32_t chunkSize = YAAL_DEFAULT_CHUNK_SIZE) : chunkSize(chunkSize)
    {
        chunks.push(Chunk(chunkSize));
    }
    template <typename U>
    ChunkAllocator(const ChunkAllocator<U> &) : chunkSize(YAAL_DEFAULT_CHUNK_SIZE) {}
    T *allocate(std::size_t n)
    {
        if (n > 1)
        {
            if (auto p = std::malloc(n * sizeof(T)))
            {
                return static_cast<T *>(p);
            }
            throw std::bad_alloc();
        }
        else if (stackT.empty())
        {
            auto p = chunks.top().getMemPtr();
            if (p == nullptr)
            {
                chunks.push(Chunk(chunkSize));
                p = chunks.top().getMemPtr();
            }
            return p;
        }
        auto p = stackT.top();
        stackT.pop();
        return p;
    }
    void deallocate(T *p, std::size_t n)
    {
        if (n > 1)
        {
            std::free(p);
        }
        else
        {
            stackT.push(p);
        }
    }

private:
    using Chunk = typename ChunkAllocatorBase<T>::Chunk;
    const u_int32_t chunkSize;
    std::stack<T *> stackT;
    std::stack<Chunk> chunks;
};

}