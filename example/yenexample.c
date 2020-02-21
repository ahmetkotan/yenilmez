//
// Created by Ahmet Kotan on 16.02.2020.
//

#include <yenilmez/yenilmez.h>
#include <unistd.h>

void
test_integers () {
    yen_test_eq(3, 3, "3 is equal to 3");
    yen_test_eq(3, 2, "3 is equal to 2");
    sleep(1);
    yen_test_neq(3, 2, "3 is not equal to 2");
}

void
test_strings () {
    yen_test_str_eq("yenilmez", "yenilmez", "yenilmez is yenilmez");
    yen_test_str_eq("yenilmez", "yenilmez2", "yenilmez is yenilmez2");
    yen_test_str_neq("yenilmez", "yenilmez2", "yenilmez is not yenilmez2");
}

int main (int argc, char *argv[]) {
    yenilmez_initialize(argc, argv);

    set_parallel_jobs(0);
    test_counts counts = run_all_tests();

    return counts.failed;
}
