#include <gtest/gtest.h>
#include <unordered_set>
#include "TestsConstants.hpp"

TEST(PerformanceComparisionTest, OnlyAdditionsPerformanceSet)
{
    std::set<long> mySet;

    for (long i = 0; i < toAdd1; ++i)
    {
        mySet.insert(i);
    }
    ASSERT_EQ(mySet.size(), toAdd1);
}

TEST(PerformanceComparisionTest, AdditionsRemovalsPerformanceSet)
{
    std::set<long> mySet;

    for (long i = 0; i < toAdd1; ++i)
    {
        mySet.insert(i);
    }
    ASSERT_EQ(mySet.size(), toAdd1);

    for (long i = toRemove; i > 0; --i)
    {
        mySet.erase(i);
    }

    for (long i = 0; i < toAdd2; ++i)
    {
        mySet.insert(i + toAdd1);
    }
}

TEST(PerformanceComparisionTest, OnlyAdditionsPerformanceHashSet)
{
    std::unordered_set<long> mySet;

    for (long i = 0; i < toAdd1; ++i)
    {
        mySet.insert(i);
    }
    ASSERT_EQ(mySet.size(), toAdd1);
}

TEST(PerformanceComparisionTest, AdditionsRemovalsPerformanceHashSet)
{
    std::unordered_set<long> mySet;

    for (long i = 0; i < toAdd1; ++i)
    {
        mySet.insert(i);
    }
    ASSERT_EQ(mySet.size(), toAdd1);

    for (long i = toRemove; i > 0; --i)
    {
        mySet.erase(i);
    }

    for (long i = 0; i < toAdd2; ++i)
    {
        mySet.insert(i + toAdd1);
    }
}