#include <unordered_set>
#include <gtest/gtest.h>
#include "TestTemplates.hpp"

#include "allocators/VariableSizeChunkAllocator.hpp"

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

TEST(VariableSizeChunkAllocatorTest, BasicValidationMap)
{
    std::map<long, DummyData, std::less<long>,
             VariableSizeChunkAllocator<std::pair<const long, DummyData>>>
        myMap;

    BasicValidationMap(myMap);
}

TEST(VariableSizeChunkAllocatorTest, OnlyAdditionsPerformanceMap)
{
    std::map<long, DummyData, std::less<long>,
             VariableSizeChunkAllocator<std::pair<const long, DummyData>>>
        myMap;

    OnlyAdditionsPerformanceMap(myMap);
}

TEST(VariableSizeChunkAllocatorTest, AdditionsRemovalsPerformanceMap)
{
    std::map<long, DummyData, std::less<long>,
             VariableSizeChunkAllocator<std::pair<const long, DummyData>>>
        myMap;

    AdditionsRemovalsPerformanceMap(myMap);
}

TEST(VariableSizeChunkAllocatorTest, BasicValidationHashMap)
{
    std::unordered_map<long, DummyData, std::hash<long>, std::equal_to<long>,
                       VariableSizeChunkAllocator<std::pair<const long, DummyData>>>
        myMap;

    BasicValidationMap(myMap);
}

TEST(VariableSizeChunkAllocatorTest, OnlyAdditionsPerformanceHashMap)
{
    std::unordered_map<long, DummyData, std::hash<long>, std::equal_to<long>,
                       VariableSizeChunkAllocator<std::pair<const long, DummyData>>>
        myMap;

    OnlyAdditionsPerformanceMap(myMap);
}

TEST(VariableSizeChunkAllocatorTest, AdditionsRemovalsPerformanceHashMap)
{
    std::unordered_map<long, DummyData, std::hash<long>, std::equal_to<long>,
                       VariableSizeChunkAllocator<std::pair<const long, DummyData>>>
        myMap;

    AdditionsRemovalsPerformanceMap(myMap);
}