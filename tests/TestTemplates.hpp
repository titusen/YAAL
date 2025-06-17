#include <gtest/gtest.h>
#include <unordered_set>

const long toAdd1 = 40000000;
const long toAdd2 = 400000;
const long toRemove = 500000;

template <typename Container>
void BasicValidation(Container &container) {
    const long toAdd1 = 500;
    for (long i = 0; i < toAdd1; ++i)
    {
        container.insert(i);
    }
    ASSERT_EQ(container.size(), toAdd1);

    const long toRemove = 400;
    for (long i = toRemove; i > 0; --i)
    {
        container.erase(i);
    }

    ASSERT_EQ(container.size(), toAdd1 - toRemove);

    const long toAdd2 = 900;
    for (long i = toAdd1; i < toAdd2; ++i)
    {
        container.insert(i);
    }

    ASSERT_EQ(container.size(), toAdd2 - toRemove);
}

template <typename Container>
void OnlyAdditionsPerformance(Container &container) {
    for (long i = 0; i < toAdd1; ++i)
    {
        container.insert(i);
    }
    ASSERT_EQ(container.size(), toAdd1);
}

template <typename Container>
void AdditionsRemovalsPerformance(Container &container) {
    for (long i = 0; i < toAdd1; ++i)
    {
        container.insert(i);
    }
    ASSERT_EQ(container.size(), toAdd1);

    for (long i = toRemove; i > 0; --i)
    {
        container.erase(i);
    }

    for (long i = 0; i < toAdd2; ++i)
    {
        container.insert(i + toAdd1);
    }
}