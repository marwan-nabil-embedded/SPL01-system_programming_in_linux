#include <stdio.h>

int echo_main(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            printf("%s", argv[i]);
            if (i < argc - 1) {
                printf(" ");  // Add a space after each argument except the last one
            }
        }
        printf("\n");
    } else {
        printf("\n");
    }
    return 0;
}

