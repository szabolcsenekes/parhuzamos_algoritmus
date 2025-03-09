#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Iteratív összegzés
int sum_iterative(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Rekurzív összegzés
int sum_recursive(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + sum_recursive(arr, n - 1);
}

// Iteratív minimumkeresés
int min_iterative(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

// Rekurzív minimumkeresés
int min_recursive(int arr[], int n) {
    if (n == 1) return arr[0];
    int min_rest = min_recursive(arr, n - 1);
    return (arr[n - 1] < min_rest) ? arr[n - 1] : min_rest;
}

// Iteratív maximumkeresés
int max_iterative(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

// Rekurzív maximumkeresés
int max_recursive(int arr[], int n) {
    if (n == 1) return arr[0];
    int max_rest = max_recursive(arr, n - 1);
    return (arr[n - 1] > max_rest) ? arr[n - 1] : max_rest;
}

int main() {
    FILE *file = fopen("results.csv", "w");
    fprintf(file, "n,iter_sum,rec_sum,iter_min,rec_min,iter_max,rec_max\n");

    for (int n = 1000; n <= 30000; n += 100) {
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000;
        }
        
        clock_t start, end;
        double time_taken;

        start = clock();
        sum_iterative(arr, n);
        end = clock();
        double iter_sum_time = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        sum_recursive(arr, n);
        end = clock();
        double rec_sum_time = (double)(end - start) / CLOCKS_PER_SEC;
        
        start = clock();
        min_iterative(arr, n);
        end = clock();
        double iter_min_time = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        min_recursive(arr, n);
        end = clock();
        double rec_min_time = (double)(end - start) / CLOCKS_PER_SEC;
        
        start = clock();
        max_iterative(arr, n);
        end = clock();
        double iter_max_time = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        max_recursive(arr, n);
        end = clock();
        double rec_max_time = (double)(end - start) / CLOCKS_PER_SEC;
        
        fprintf(file, "%d,%lf,%lf,%lf,%lf,%lf,%lf\n", n, iter_sum_time, rec_sum_time, iter_min_time, rec_min_time, iter_max_time, rec_max_time);

        free(arr);
    }
    fclose(file);
    return 0;
}
