//
// Created by Ahmet Dino on 21.02.2020.
//

#include "counters.h"

int TEST_COUNT = 0;
int PASSED_COUNT = 0;
int FAILED_COUNT = 0;

void
increase_passed_count () {
    PASSED_COUNT++;
    TEST_COUNT++;
}

void
increase_failed_count () {
    FAILED_COUNT++;
    TEST_COUNT++;
}

int
get_test_count () {
    return TEST_COUNT;
}

int
get_passed_count () {
    return PASSED_COUNT;
}

int
get_failed_count () {
    return FAILED_COUNT;
}

test_counts
get_test_report () {
    test_counts counts;

    counts.passed = get_passed_count();
    counts.failed = get_failed_count();
    counts.total = get_test_count();

    return counts;
}

