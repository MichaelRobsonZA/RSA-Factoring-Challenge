#include <stdio.h>
#include <math.h>
#include "factors.h"

void factorizeNumber(int number) {
    int i, factor1, factor2;

    for (i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            factor1 = i;
            factor2 = number / i;
            printf("%d=%d*%d\n", number, factor1, factor2);
            return;
        }
    }

    printf("%d is a prime number\n", number);
}

void factorizeNumbersFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    int number;

    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    while (fscanf(file, "%d\n", &number) != EOF) {
        factorizeNumber(number);
    }

    fclose(file);
}
