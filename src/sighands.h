//
// Created by Ahmet Kotan on 21.02.2020.
//

#ifndef YENILMEZ_SIGHANDS_H
#define YENILMEZ_SIGHANDS_H

#define PASSED_SIGNAL 41
#define FAILED_SIGNAL 42

int signal_catch;

void
signal_handlers_initialize ();

void
custom_signal_handler_initialize (int signal);

#endif //YENILMEZ_SIGHANDS_H
