//
// Created by Ahmet Kotan on 21.02.2020.
//

#include <glib.h>
#include <stdio.h>

#include "jobs.h"
#include "colors.h"

int job_count = 1;
GSList *pid_list = NULL;

void
set_parallel_jobs (int j) {
    if (j < 1) {
        print_warning("[WARNING]: Parallel jobs can be at least 1.\n");
        return;
    }
    job_count = j;
}

int
get_job_count () {
    return job_count;
}

int
check_job_pid (pid_t pid) {
    if (pid == (pid_t) -1)
        return 0;

    GSList *tmp = g_slist_find(pid_list, GINT_TO_POINTER(pid));
    if (tmp == NULL)
        return 0;

    pid_list = g_slist_remove(pid_list, tmp);
    return 1;
}

void
add_job_pid (pid_t pid) {
    pid_list = g_slist_append(pid_list, GINT_TO_POINTER(pid));
}

void
delete_pid_list () {
    g_slist_free(pid_list);
}
