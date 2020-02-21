//
// Created by Ahmet Kotan on 15.02.2020.
//

#ifndef YENILMEZLER_YENILMEZLER_H
#define YENILMEZLER_YENILMEZLER_H

#include "assertion.h"
#include "counters.h"
#include "jobs.h"

typedef void (*test_func) (void *);

struct test_functions {
    test_func func;
    struct test_functions *next;
};
typedef struct test_functions test_f;

test_counts
run_all_tests ();

void
yenilmez_initialize (int argc, char *argv[]);

#endif //YENILMEZLER_YENILMEZLER_H
