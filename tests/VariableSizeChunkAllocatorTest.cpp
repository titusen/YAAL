#include <unordered_set>
#include <gtest/gtest.h>
#include "TestTemplates.hpp"

#include "YAAL.hpp"

using yaal::VariableSizeChunkAllocator;

TEST(VariableSizeChunkAllocatorTest, BasicValidation)
{
    std::set<long, std::less<long>, VariableSizeChunkAllocator<long>> mySet;

    BasicValidation(mySet);
}

TEST(VariableSizeChunkAllocatorTest, OnlyAdditionsPerformanceSet)
{
    std::set<long, std::less<long>, VariableSizeChunkAllocator<long>> mySet;

    OnlyAdditionsPerformance(mySet);
}

TEST(VariableSizeChunkAllocatorTest, AdditionsRemovalsPerformanceSet)
{
    std::set<long, std::less<long>, VariableSizeChunkAllocator<long>> mySet;

    AdditionsRemovalsPerformance(mySet);
}

TEST(VariableSizeChunkAllocatorTest, OnlyAdditionsPerformanceHashSet)
{
    std::unordered_set<long, std::hash<long>,
                       std::equal_to<long>,
                       VariableSizeChunkAllocator<long>>
        mySet;
    OnlyAdditionsPerformance(mySet);
}

TEST(VariableSizeChunkAllocatorTest, AdditionsRemovalsPerformanceHashSet)
{
    std::unordered_set<long, std::hash<long>,
                       std::equal_to<long>,
                       VariableSizeChunkAllocator<long>>
        mySet;

    AdditionsRemovalsPerformance(mySet);
}