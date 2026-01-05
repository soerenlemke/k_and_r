//
// Created by soerenlemke on 05.01.26.
//

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

double fahrenheit_to_celsius(double temp);

int main() {
    for (int i = LOWER; i <= UPPER; i += STEP) {
        const double celsius = fahrenheit_to_celsius(i);
        printf("%3d %6.1f\n", i, celsius);
    }
}

double fahrenheit_to_celsius(const double temp) {
    return 5.0 / 9.0 * (temp - 32.0);
}
