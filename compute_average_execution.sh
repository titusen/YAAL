#!/bin/bash
# This script computes the average execution time of a specific test in CTest.
# Usage: build$ ./compute_average_execution.sh <test_name_regex> <iterations>


if [ $# -lt 2 ]; then
    echo "Usage: $0 <test_name_regex> <iterations>"
    exit 1
fi

test_name="$1"
iterations="$2"
total=0

for ((i=1; i<=iterations; i++)); do
    t=$(ctest -R "$test_name" | grep "Total Test time" | awk '{print $6}')
    total=$(echo "$total + $t" | bc)
done

avg=$(echo "scale=4; $total/$iterations" | bc)
echo "Average test time for '$test_name' over $iterations runs: $avg seconds"