//
// Created by soerenlemke on 02.01.26.
//

#include <stdio.h>

int main() {
    const double lower = -17.8;
    const double upper = 148.9;

    // table header
    printf("Fahr   Cel\n");

    double celsius = lower;
    while(celsius <= upper) {
        const double step = 11.1;

        const double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
        printf("%3.1f %6.1f\n", celsius, fahrenheit);
        celsius += step;
    }
}