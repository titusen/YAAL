#include <gtest/gtest.h>
#include <unordered_set>
#include "TestTemplates.hpp"

TEST(PerformanceComparisionTest, OnlyAdditionsPerformanceSet)
{
    std::set<long> mySet;

    OnlyAdditionsPerformance(mySet);
}

TEST(PerformanceComparisionTest, AdditionsRemovalsPerformanceSet)
{
    std::set<long> mySet;

    AdditionsRemovalsPerformance(mySet);
}

TEST(PerformanceComparisionTest, OnlyAdditionsPerformanceHashSet)
{
    std::unordered_set<long> mySet;

    OnlyAdditionsPerformance(mySet);
}

TEST(PerformanceComparisionTest, AdditionsRemovalsPerformanceHashSet)
{
    std::unordered_set<long> mySet;

    AdditionsRemovalsPerformance(mySet);
}

TEST(PerformanceComparisionTest, OnlyAdditionsPerformanceMap)
{
    std::map<long, DummyData> myMap;

    OnlyAdditionsPerformanceMap(myMap);
}

TEST(PerformanceComparisionTest, AdditionsRemovalsPerformanceMap)
{
    std::map<long, DummyData> myMap;

    AdditionsRemovalsPerformanceMap(myMap);
}

TEST(PerformanceComparisionTest, OnlyAdditionsPerformanceHashMap)
{
    std::unordered_map<long, DummyData> myMap;

    OnlyAdditionsPerformanceMap(myMap);
}

TEST(PerformanceComparisionTest, AdditionsRemovalsPerformanceHashMap)
{
    std::unordered_map<long, DummyData> myMap;

    AdditionsRemovalsPerformanceMap(myMap);
}