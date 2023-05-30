#include "factors.h"

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    const char* filename;
    filename = argv[1];
    factorizeNumbersFromFile(filename);

    return (0);
}

