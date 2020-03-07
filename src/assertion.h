//
// Created by Ahmet Kotan on 15.02.2020.
//

#ifndef YENILMEZLER_ASSERTION_H
#define YENILMEZLER_ASSERTION_H

int
yen_test (void *argument, char *message);

int
yen_test_null (void *argument, char *message);

int
yen_test_eq (int source, int destination, char *message);

int
yen_test_neq (int source, int destination, char *message);

int
yen_test_lt (int source, int destination, char *message);

int
yen_test_lte (int source, int destination, char *message);

int
yen_test_gt (int source, int destination, char *message);

int
yen_test_gte (int source, int destination, char *message);

int
yen_test_str_eq (char *source, char *destination, char *message);

int
yen_test_str_neq (char *source, char *destination, char *message);

void
yen_test_catch_signal (void *function, void *arguments, int signal, char *message);

void
yen_test_exit_status (void *function, void *arguments, int exit_status, char *message);


#endif //YENILMEZLER_ASSERTION_H
