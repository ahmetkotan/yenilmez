//
// Created by Ahmet Kotan on 21.02.2020.
//

#ifndef YENILMEZ_JOBS_H
#define YENILMEZ_JOBS_H

#include <unistd.h>

void
set_parallel_jobs (int j);

int
get_job_count ();

int
check_job_pid (pid_t pid);

void
add_job_pid (pid_t pid);

void
delete_pid_list ();

#endif //YENILMEZ_JOBS_H
