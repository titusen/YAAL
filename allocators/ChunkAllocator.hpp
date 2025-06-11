#include <memory>
#include <stack>

#ifndef YAAL_DEFAULT_CHUNK_SIZE
    #define YAAL_DEFAULT_CHUNK_SIZE 264
#endif

template <typename T>
class ChunkAllocator
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
    const u_int32_t chunkSize;
    std::stack<T *> stackT;
    std::stack<Chunk> chunks;
};
