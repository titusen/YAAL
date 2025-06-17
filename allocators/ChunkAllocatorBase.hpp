#pragma once
#include <cstddef>
#include <new>

namespace yaal {

template <typename T>
class ChunkAllocatorBase : public std::allocator<T>
{
public:
    using value_type = T;

    template <typename U>
    ChunkAllocatorBase(const ChunkAllocatorBase<U>&) noexcept {}
    
    T* allocate(std::size_t n) {
        if (auto p = static_cast<T*>(::operator new(n * sizeof(T)))) {
            return p;
        }
        throw std::bad_alloc();
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
    ~ChunkAllocatorBase() = default;
protected:
    ChunkAllocatorBase() noexcept = default;
    // Prevent copying and assignment
    ChunkAllocatorBase(const ChunkAllocatorBase&) = delete;
    ChunkAllocatorBase& operator=(const ChunkAllocatorBase&) = delete;
    ChunkAllocatorBase(ChunkAllocatorBase&&) = delete;
    ChunkAllocatorBase& operator=(ChunkAllocatorBase&&) = delete;
    
    class Chunk
    {
    private:
        void *ptr;
        u_int32_t counter;
        const u_int32_t chunkSize;

    public:
        Chunk(const u_int32_t chunkSize) : counter(0), chunkSize(chunkSize)
        {
            ptr = std::malloc(chunkSize * sizeof(T));
            if (ptr == nullptr)
            {
                throw std::bad_alloc();
            }
        }
        Chunk(Chunk&) = delete;
        Chunk(Chunk &&chunk) : chunkSize(chunk.chunkSize)
        {
            ptr = chunk.ptr;
            chunk.ptr = nullptr;
            counter = chunk.counter;
        }
        ~Chunk()
        {
            if (ptr)
            {
                std::free(ptr);
            }
        }
        T *getMemPtr()
        {
            if (counter == chunkSize - 1)
            {
                return nullptr;
            }
            return reinterpret_cast<T *>(reinterpret_cast<char *>(ptr) + sizeof(T) * (++counter));
        }
    };

    std::stack<T *> stackT;
    std::stack<Chunk> chunks;
};

template <typename T, typename U>
constexpr bool operator==(const ChunkAllocatorBase<T>&, const ChunkAllocatorBase<U>&) noexcept {
    return true;
}

template <typename T, typename U>
constexpr bool operator!=(const ChunkAllocatorBase<T>&, const ChunkAllocatorBase<U>&) noexcept {
    return false;
}

} // namespace yaal