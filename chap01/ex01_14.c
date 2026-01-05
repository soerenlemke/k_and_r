//
// Created by soerenlemke on 05.01.26.
//

#define BYTES 256
#include <stdio.h>

int main() {
    int c;
    unsigned long counts[BYTES] = {0};

    while ((c = getchar()) != EOF) {
        counts[(unsigned char) c]++;
    }

    for (int i = 0; i < BYTES; i++) {
        printf("%d: ", i);
        for (unsigned long j = 0; j < counts[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }
}
