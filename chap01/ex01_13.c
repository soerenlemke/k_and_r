//
// Created by soerenlemke on 04.01.26.
//

#include <stdio.h>

#define LONGEST_WORD 20 // limits the longest counted word size

int main() {
    int c;
    int length_counter = 0;
    int lengths[LONGEST_WORD];

    // count length of each word and write to array
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (length_counter > 0 && length_counter < LONGEST_WORD) {
                lengths[length_counter] += 1;
                length_counter = 0;
            } else {
                // prevent error if a word is bigger than array
                lengths[LONGEST_WORD - 1] += 1;
                length_counter = 0;
            }
        } else {
            length_counter++;
        }
    }

    // print histogram -> logic limited to 100 atm
    for (int i = 0; i <= LONGEST_WORD - 1; i++) {
        printf("%d: ", i);
        for (int j = 0; j < lengths[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }
}
