#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n)
{
    int i;

    if (n <= 1)
        return 0;

    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

void factorize(int n)
{
    int i;
    int factor1 = -1, factor2 = -1;

    if (n == 0)
    {
        printf("Unable to factorize %d\n", n);
        return;
    }

    if (n < 0)
    {
        n = -n;  /* Convert negative number to positive */
        printf("%d=-1*%d\n", n, n);
        return;
    }

    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            factor1 = i;
            factor2 = n / i;
            break;
        }
    }

    if (factor1 != -1 && factor2 != -1)
        printf("%d=%d*%d\n", n, factor1, factor2);
    else if (is_prime(n))
        printf("%d is a prime number\n", n);
    else
        printf("Unable to factorize %d\n", n);
}



void factorize_from_file(const char *filename)
{
    FILE *file;
    int num;

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    while (fscanf(file, "%d", &num) == 1)
    {
        factorize(num);
    }

    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: factors <file>\n");
        return 1;
    }

    factorize_from_file(argv[1]);

    return 0;
}

