#include <gtest/gtest.h>
#include <unordered_set>
#include "YAAL.hpp"



TEST(ChunkAllocatorTest, BasicValidation)
{
    std::set<long, std::less<long>, ChunkAllocator<long>> mySet;

    const long toAdd1 = 500;
    for (long i = 0; i < toAdd1; ++i) {
        mySet.insert(i);
    }
    ASSERT_EQ(mySet.size(), toAdd1);

    const long toRemove = 400;
    for (long i = toRemove;i > 0; --i) {
        mySet.erase(i);
    }

    ASSERT_EQ(mySet.size(), toAdd1 - toRemove);

    const long toAdd2 = 900;
    for (long i = toAdd1; i < toAdd2; ++i) {
        mySet.insert(i);
    }

    ASSERT_EQ(mySet.size(), toAdd2 - toRemove);
}

TEST(ChunkAllocatorTest, OnlyAdditionsPerformanceSet)
{
    std::set<long, std::less<long>, ChunkAllocator<long>> mySet;

    const long toAdd1 = 40000000;
    for (long i = 0; i < toAdd1; ++i) {
        mySet.insert(i);
    }
    ASSERT_EQ(mySet.size(), toAdd1);
}

TEST(ChunkAllocatorTest, AdditionsRemovalsPerformanceSet)
{
    std::set<long, std::less<long>, ChunkAllocator<long>> mySet;

    const long toAdd1 = 40000000;
    for (long i = 0; i < toAdd1; ++i) {
        mySet.insert(i);
    }
    ASSERT_EQ(mySet.size(), toAdd1);

    const long toRemove = 500000;
    for (long i = toRemove;i > 0; --i) {
        mySet.erase(i);
    }

    const long toAdd2 = 400000;
    for (long i = 0; i < toAdd2; ++i) {
        mySet.insert(i + toAdd1);
    }
}

TEST(ChunkAllocatorTest, OnlyAdditionsPerformanceHashSet)
{
    std::unordered_set<long, std::hash<long>,
    std::equal_to<long>,ChunkAllocator<long>> mySet;

    const long toAdd1 = 40000000;
    for (long i = 0; i < toAdd1; ++i) {
        mySet.insert(i);
    }
    ASSERT_EQ(mySet.size(), toAdd1);
}

TEST(ChunkAllocatorTest, AdditionsRemovalsPerformanceHashSet)
{
    std::set<long, std::less<long>, ChunkAllocator<long>> mySet;

    const long toAdd1 = 40000000;
    for (long i = 0; i < toAdd1; ++i) {
        mySet.insert(i);
    }
    ASSERT_EQ(mySet.size(), toAdd1);

    const long toRemove = 500000;
    for (long i = toRemove;i > 0; --i) {
        mySet.erase(i);
    }

    const long toAdd2 = 400000;
    for (long i = 0; i < toAdd2; ++i) {
        mySet.insert(i + toAdd1);
    }
}