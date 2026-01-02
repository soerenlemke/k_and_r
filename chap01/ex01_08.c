//
// Created by soerenlemke on 02.01.26.
//

#include <stdio.h>

// testable by running and then STRG + D for ending console

int main() {
    int character;
    int newline_counter = 0;
    int tab_counter = 0;
    int blank_counter = 0;

    while ((character = getchar()) != EOF) {
        if (character == '\n') {
            newline_counter++;
        }
        if (character == '\t') {
            tab_counter++;
        }
        if (character == ' ') {
            blank_counter++;
        }
    }

    printf("Newline counter: %d\n", newline_counter);
    printf("Tab counter: %d\n", tab_counter);
    printf("Blank counter: %d\n", blank_counter);
}
