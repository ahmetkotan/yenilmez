//
// Created by Ahmet Dino on 21.02.2020.
//

#ifndef YENILMEZ_COUNTERS_H
#define YENILMEZ_COUNTERS_H


typedef struct {
    int passed;
    int failed;
    int total;
} test_counts;

void
increase_passed_count ();

void
increase_failed_count ();

int
get_test_count ();

int
get_passed_count ();

int
get_failed_count ();

test_counts
get_test_report ();

#endif //YENILMEZ_COUNTERS_H
