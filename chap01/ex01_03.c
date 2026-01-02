//
// Created by soerenlemke on 02.01.26.
//

#include <stdio.h>

int main() {
    const double lower = 0;
    const double upper = 300;

    // table header
    printf("Cel   Fahr\n");

    double fahr = lower;
    while(fahr <= upper) {
        const int step = 20;
        const double celsius = 5.0 / 9.0 * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
