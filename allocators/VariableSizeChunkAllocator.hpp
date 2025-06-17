#pragma once

#include <cstdint>
#include "ChunkAllocatorBase.hpp"

namespace yaal {
#ifndef YAAL_DEFAULT_CHUNK_SIZE
    #define YAAL_DEFAULT_CHUNK_SIZE 264
#endif

#ifndef YAAL_MODIFY_CHUNK_SIZE
    #define YAAL_MODIFY_CHUNK_SIZE 1
    // Due to stl allocator requirements, there is a need to provide a way to modify the chunk size.
    // There is no way to pass it to a constructor.
    // struct ChunkSizeModifier
    // {
    //     uint32_t incrementBy;
    //     ChunkSizeModifier(const uint32_t incrementBy = 32) : incrementBy(incrementBy) {}
    //     void modifyChunkSize(uint32_t &chunkSize) const
    //     {
    //         chunkSize += incrementBy;
    //     }
    // };

    struct ChunkSizeModifier
    {
        const double multiplyBy;
        ChunkSizeModifier(const double multiplyBy = 1.24) : multiplyBy(multiplyBy) {}
        void modifyChunkSize(uint32_t &chunkSize) const
        {
            chunkSize *= multiplyBy;
        }
    };
    
#endif

template<typename T>
class VariableSizeChunkAllocator : public ChunkAllocatorBase<T>
{
public:
    using value_type = T;
    using Chunk = typename ChunkAllocatorBase<T>::Chunk;
    using ChunkAllocatorBase<T>::stackT;
    using ChunkAllocatorBase<T>::chunks;
    VariableSizeChunkAllocator(uint32_t chunkSize = YAAL_DEFAULT_CHUNK_SIZE): chunkSize(chunkSize) 
    {
        chunks.push(Chunk(chunkSize));
    }
    ~VariableSizeChunkAllocator() = default;

    template <typename U>
    VariableSizeChunkAllocator(const VariableSizeChunkAllocator<U> &) : chunkSize(YAAL_DEFAULT_CHUNK_SIZE) {}
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
                chunkSizeModifier.modifyChunkSize(chunkSize);
                chunks.push(Chunk(chunkSize));
                p = chunks.top().getMemPtr();
            }
            return p;
        }
        auto p = stackT.top();
        stackT.pop();
        return p;
    }

private:
    u_int32_t chunkSize;
    ChunkSizeModifier chunkSizeModifier;
    // Prevent copying and assignment
    VariableSizeChunkAllocator(const VariableSizeChunkAllocator&) = delete;
    VariableSizeChunkAllocator& operator=(const VariableSizeChunkAllocator&) = delete;
    VariableSizeChunkAllocator(VariableSizeChunkAllocator&&) = delete;
    VariableSizeChunkAllocator& operator=(VariableSizeChunkAllocator&&) = delete;
};

}
