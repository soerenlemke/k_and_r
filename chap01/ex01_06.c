//
// Created by soerenlemke on 02.01.26.
//

#include <stdio.h>

int main() {
    const int c = getchar();
    const int is_not_eof = c != EOF;

    printf("%d\n", is_not_eof);
}
