//
// Created by Ahmet Kotan on 21.02.2020.
//

#ifndef YENILMEZ_COUNTERS_H
#define YENILMEZ_COUNTERS_H


typedef struct {
    int passed;
    int failed;
    int total;
    int cases;
} test_counts;

void
increase_passed_count ();

void
increase_failed_count ();

void
increase_case_count ();

int
get_assertion_count ();

int
get_passed_count ();

int
get_failed_count ();

int
get_case_count ();

test_counts
get_test_report ();

#endif //YENILMEZ_COUNTERS_H
