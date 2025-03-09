#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <lower bound> <upper bound>\n", argv[0]);
        return 1;
    }

    int lower = atoi(argv[1]);
    int upper = atoi(argv[2]);

    if (lower > upper) {
        fprintf(stderr, "Error: Lower bound cannot be greater than upper bound.\n");
        return 1;
    }

    srand(time(NULL));
    int random_int = lower + rand() % (upper - lower + 1);
    printf("Random integer in [%d, %d]: %d\n", lower, upper, random_int);

    return 0;
}