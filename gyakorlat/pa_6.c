#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int count_primes(int n) {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) count++;
    }
    return count;
}

int main() {
    FILE *file = fopen("prime_counts.csv", "w");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fprintf(file, "n,Prime Count,Time (seconds)\n");

    clock_t start, end;
    double cpu_time_used;

    for (int n = 1000; n <= 20000; n += 1000) {
        start = clock();
        int prime_count = count_primes(n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(file, "%d,%d,%.6f\n", n, prime_count, cpu_time_used);
    }

    fclose(file);
    printf("Results saved to prime_counts.csv.\n");

    return 0;
}
