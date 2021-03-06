//
// Created by Ahmet Kotan on 21.02.2020.
//

#include <signal.h>
#include <string.h>
#include <glib.h>

#include "sighands.h"
#include "counters.h"


void
passed_signal_handler (int signal, siginfo_t *info, void *context) {
    if (signal == PASSED_SIGNAL) {
        increase_passed_count();
    }
}

void
failed_signal_handler (int signal, siginfo_t *info, void *context) {
    if (signal == FAILED_SIGNAL) {
        increase_failed_count();
    }
}

void
signal_handlers_initialize () {
    struct sigaction passed_action;
    memset(&passed_action, 0, sizeof(passed_action));
    passed_action.sa_sigaction = &passed_signal_handler;
    sigaction(PASSED_SIGNAL, &passed_action, NULL);

    struct sigaction failed_action;
    memset(&failed_action, 0, sizeof(failed_action));
    failed_action.sa_sigaction = &failed_signal_handler;
    sigaction(FAILED_SIGNAL, &failed_action, NULL);
}

int global_signal;
void
custom_signal_handler (int signal, siginfo_t *info, void *context) {
    if (signal == global_signal)
        signal_catch = 1;
}

void
custom_signal_handler_initialize (int signal) {
    signal_catch = 0;
    global_signal = signal;

    struct sigaction custom_action;
    memset(&custom_action, 0, sizeof(custom_action));
    custom_action.sa_sigaction = &custom_signal_handler;
    sigaction(signal, &custom_action, NULL);
}
