//
// Created by Ahmet Kotan on 15.02.2020.
//

#include <stdlib.h>
#include <glib.h>
#include <dlfcn.h>

#include "yenilmez.h"
#include "collector.h"
#include "colors.h"
#include "sighands.h"
#include "counters.h"

test_f *flist_head = NULL;
void *handle;

void
call_function (test_f *function) {
    (*(function->func))(NULL);
}

test_counts
run_all_tests () {
    test_f *tmp = flist_head;

    while (tmp) {
        call_function(tmp);
        tmp = tmp->next;
    }
    dlclose(handle);

    print_counts();
    print_credits();

    return get_test_report();
}

test_f *
get_last_function () {
    test_f *tmp = flist_head;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    return tmp;
}

void
add_test_function (test_func function) {
    test_f *new_function = (test_f *) malloc(sizeof(test_f));
    new_function->func = function;
    new_function->next = NULL;

    if (flist_head == NULL) {
        flist_head = new_function;
    } else {
        test_f *last = get_last_function();
        last->next = new_function;
    }
}

void
discover_functions (char *argv[]) {
    GSList *functions = collect_test_functions(argv[0]);

    handle = dlopen(argv[0], RTLD_LAZY);
    while (functions != NULL) {
        void(*function)();
        function = (void(*)()) dlsym(handle, functions->data);
        add_test_function(function);
        functions = g_slist_next(functions);
    }

    g_slist_free(functions);
}

void
yenilmez_initialize (int argc, char *argv[]) {
    discover_functions(argv);
    signal_handlers_initialize ();
}
