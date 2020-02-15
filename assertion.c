//
// Created by Ahmet Kotan on 15.02.2020.
//
#include <glib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "colors.h"

int
yen_test (void *argument, char *message) {
    if (argument)
        print_passed(message);
    else
        print_failed(message);
}

int
yen_test_null (void *argument, char *message) {
    if (argument == NULL)
        print_passed(message);
    else
        print_failed(message);
}

void
yen_test_int (int result, char *success_message, char *fail_message) {
    if (result)
        print_passed(success_message);
    else {
        if (success_message)
            success_message = g_strconcat(success_message, " -> ", fail_message, NULL);
        else
            success_message = g_strdup(fail_message);
        print_failed(success_message);
    }
}

int
yen_test_eq (int source, int destination, char *message) {
    int ret = source == destination;

    char *not_equal = (char *) malloc(50);
    sprintf(not_equal, "%d != %d", source, destination);
    yen_test_int(ret, message, not_equal);

    free(not_equal);
    return ret;
}

int
yen_test_neq (int source, int destination, char *message) {
    int ret = source != destination;

    char *equal = (char *) malloc(50);
    sprintf(equal, "variables is equal to %d", source);
    yen_test_int(ret, message, equal);

    free(equal);
    return ret;
}

int
yen_test_lt (int source, int destination, char *message) {
    int ret = source < destination;

    char *equal = (char *) malloc(50);
    sprintf(equal, "%d !< %d", source, destination);
    yen_test_int(ret, message, equal);

    free(equal);
    return ret;
}

int
yen_test_lte (int source, int destination, char *message) {
    int ret = source <= destination;

    char *equal = (char *) malloc(50);
    sprintf(equal, "%d !< or != %d", source, destination);
    yen_test_int(ret, message, equal);

    free(equal);
    return ret;
}

int
yen_test_gt (int source, int destination, char *message) {
    int ret = source > destination;

    char *equal = (char *) malloc(50);
    sprintf(equal, "%d !> %d", source, destination);
    yen_test_int(ret, message, equal);

    free(equal);
    return ret;
}

int
yen_test_gte (int source, int destination, char *message) {
    int ret = source >= destination;

    char *equal = (char *) malloc(50);
    sprintf(equal, "%d !>= %d", source, destination);
    yen_test_int(ret, message, equal);

    free(equal);
    return ret;
}

void
yen_test_str (int result, char *succes_message, char *fail_message) {
    if (result)
        print_passed(succes_message);
    else {
        if (succes_message) {
            succes_message = g_strconcat(succes_message, " -> ", fail_message, NULL);
        }
        else
            succes_message = g_strdup(fail_message);

        print_failed(succes_message);
    }
}

int
yen_test_str_eq (char *source, char *destination, char *message) {
    int ret = strcmp(source, destination);

    char *not_equal = NULL;
    not_equal = g_strconcat(source, " != ", destination, NULL);
    yen_test_str(!ret, message, not_equal);

    free(not_equal);

    return ret;
}

int
yen_test_str_neq (char *source, char *destination, char *message) {
    int ret = strcmp(source, destination);

    char *equal = NULL;
    equal = g_strconcat("variables is equal to ", source, NULL);
    yen_test_str(ret, message, equal);

    free(equal);

    return ret;
}
