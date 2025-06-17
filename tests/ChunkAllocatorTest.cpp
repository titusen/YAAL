#include <gtest/gtest.h>
#include <unordered_set>
#include "YAAL.hpp"
#include "TestTemplates.hpp"

using yaal::ChunkAllocator;

TEST(ChunkAllocatorTest, BasicValidation)
{
    std::set<long, std::less<long>, ChunkAllocator<long>> mySet;

    BasicValidation(mySet);
}

TEST(ChunkAllocatorTest, OnlyAdditionsPerformanceSet)
{
    std::set<long, std::less<long>, ChunkAllocator<long>> mySet;

    OnlyAdditionsPerformance(mySet);
}

TEST(ChunkAllocatorTest, AdditionsRemovalsPerformanceSet)
{
    std::set<long, std::less<long>, ChunkAllocator<long>> mySet;

    AdditionsRemovalsPerformance(mySet);
}

TEST(ChunkAllocatorTest, OnlyAdditionsPerformanceHashSet)
{
    std::unordered_set<long, std::hash<long>,
                       std::equal_to<long>,
                       ChunkAllocator<long>>
        mySet;
    OnlyAdditionsPerformance(mySet);
}

TEST(ChunkAllocatorTest, AdditionsRemovalsPerformanceHashSet)
{
    std::unordered_set<long, std::hash<long>,
                       std::equal_to<long>,
                       ChunkAllocator<long>>
        mySet;

    AdditionsRemovalsPerformance(mySet);
}