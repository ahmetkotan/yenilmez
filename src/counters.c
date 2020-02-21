//
// Created by Ahmet Kotan on 21.02.2020.
//

#include "counters.h"


int CASE_COUNT = 0;
int ASSERTION_COUNT = 0;
int PASSED_COUNT = 0;
int FAILED_COUNT = 0;

void
increase_passed_count () {
    PASSED_COUNT++;
    ASSERTION_COUNT++;
}

void
increase_failed_count () {
    FAILED_COUNT++;
    ASSERTION_COUNT++;
}

void
increase_case_count () {
    CASE_COUNT++;
}

int
get_assertion_count () {
    return ASSERTION_COUNT;
}

int
get_passed_count () {
    return PASSED_COUNT;
}

int
get_failed_count () {
    return FAILED_COUNT;
}

int
get_case_count () {
    return CASE_COUNT;
}

test_counts
get_test_report () {
    test_counts counts;

    counts.passed = get_passed_count();
    counts.failed = get_failed_count();
    counts.total = get_assertion_count();
    counts.cases = get_case_count();

    return counts;
}

