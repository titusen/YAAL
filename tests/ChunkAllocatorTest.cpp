#include <gtest/gtest.h>
#include <unordered_set>
#include "allocators/ChunkAllocator.hpp"
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

TEST(ChunkAllocatorTest, BasicValidationMap)
{
    std::map<long, DummyData, std::less<long>, ChunkAllocator<std::pair<const long, DummyData>>> myMap;

    BasicValidationMap(myMap);
}

TEST(ChunkAllocatorTest, OnlyAdditionsPerformanceMap)
{
    std::map<long, DummyData, std::less<long>, ChunkAllocator<std::pair<const long, DummyData>>> myMap;

    OnlyAdditionsPerformanceMap(myMap);
}

TEST(ChunkAllocatorTest, AdditionsRemovalsPerformanceMap)
{
    std::map<long, DummyData, std::less<long>, ChunkAllocator<std::pair<const long, DummyData>>> myMap;

    AdditionsRemovalsPerformanceMap(myMap);
}

TEST(ChunkAllocatorTest, BasicValidationHashMap)
{
    std::unordered_map<long, DummyData, std::hash<long>, std::equal_to<long>, ChunkAllocator<std::pair<const long, DummyData>>> myMap;

    BasicValidationMap(myMap);
}

TEST(ChunkAllocatorTest, OnlyAdditionsPerformanceHashMap)
{
    std::unordered_map<long, DummyData, std::hash<long>, std::equal_to<long>, ChunkAllocator<std::pair<const long, DummyData>>> myMap;

    OnlyAdditionsPerformanceMap(myMap);
}

TEST(ChunkAllocatorTest, AdditionsRemovalsPerformanceHashMap)
{
    std::unordered_map<long, DummyData, std::hash<long>, std::equal_to<long>, ChunkAllocator<std::pair<const long, DummyData>>> myMap;

    AdditionsRemovalsPerformanceMap(myMap);
}