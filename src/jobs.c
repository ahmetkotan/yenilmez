//
// Created by Ahmet Kotan on 21.02.2020.
//

#include <stdio.h>

#include "jobs.h"
#include "colors.h"

int job_count = 1;

void
set_parallel_jobs (int j) {
    if (j < 1) {
        print_warning("Parallel jobs can be at least 1.\n");
        return;
    }
    job_count = j;
}

int
get_job_count () {
    return job_count;
}
