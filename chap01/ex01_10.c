//
// Created by soerenlemke on 04.01.26.
//

#include <stdio.h>

int main() {
    int character;

    while ((character = getchar()) != EOF) {
        if (character == '\\') {
            putchar('\\');
            putchar('\\');
        } else if (character == '\t') {
            putchar('\\');
            putchar('t');
        } else if (character == ' ') {
            putchar('\\');
            putchar('b');
        } else {
            putchar(character);
        }
    }
}
