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