#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{
	int i;

	if (n <= 1)
		return 0;

	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return 0;
	}

	return 1;
}

void factorize(int n)
{
	int i;

	for (i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			int factor1 = i;
			int factor2 = n / i;
			printf("%d=%d*%d\n", n, factor1, factor2);
			return;
		}
	}

	printf("%d is a prime number\n", n);
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

