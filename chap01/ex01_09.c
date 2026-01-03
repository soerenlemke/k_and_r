//
// Created by soerenlemke on 03.01.26.
//

#include <stdio.h>

int main() {
    int character;
    int last_character = EOF;

    while ((character = getchar()) != EOF) {
        if (character != ' ' || last_character != ' ') {
            putchar(character);
        }

        last_character = character;
    }
}
