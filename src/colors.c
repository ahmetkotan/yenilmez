//
// Created by Ahmet Kotan on 15.02.2020.
//

#include <stdio.h>
#include <signal.h>
#include <unistd.h>


#include "counters.h"
#include "sighands.h"

char *RED_TERMINAL = "\033[1;31m";
char *GREEN_TERMINAL = "\033[1;32m";
char *YELLOW_TERMINAL = "\033[1;33m";
char *BLUE_TERMINAL = "\033[1;34m";
char *RESET_COLORS = "\033[0m";

void
print_warning (char *message) {
    fprintf(stdout, "%s%s%s\n", YELLOW_TERMINAL, message, RESET_COLORS);
}

void
print_passed (char *message) {
    if (message)
        fprintf(stdout, "%s[PASSED] %s: %s\n", GREEN_TERMINAL, RESET_COLORS, message);
    else
        fprintf(stdout, "%s[PASSED] %s\n", GREEN_TERMINAL, RESET_COLORS);

    kill(getppid(), PASSED_SIGNAL);
}

void
print_failed (char *message) {
    if (message)
        fprintf(stderr, "%s[FAILED] %s: %s\n", RED_TERMINAL, RESET_COLORS, message);
    else
        fprintf(stderr, "%s[FAILED] %s\n", RED_TERMINAL, RESET_COLORS);

    kill(getppid(), FAILED_SIGNAL);
}

void
print_counts () {
    fprintf(stdout, "\n\n");
    fprintf(stdout, "%s[Test Cases]: %d%s ", YELLOW_TERMINAL, get_case_count(), RESET_COLORS);
    fprintf(stdout, "%s[Assertions]: %d%s ", BLUE_TERMINAL, get_assertion_count(), RESET_COLORS);
    fprintf(stdout, "%s[Passed]: %d%s ", GREEN_TERMINAL, get_passed_count(), RESET_COLORS);
    fprintf(stdout, "%s[Failed]: %d%s ", RED_TERMINAL, get_failed_count(), RESET_COLORS);
    fprintf(stdout, "\n");
}

void
print_credits () {
    fprintf(stdout, "\n%s[YENILMEZ C Test Framework]\n", BLUE_TERMINAL);
    fprintf(stdout, "[https://github.com/ahmetkotan/yenilmez]%s\n\n", RESET_COLORS);
}
