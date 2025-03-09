#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_numbers(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 10000;
    }
}

void write_to_file(const char *filename, int *array, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fwrite(array, sizeof(int), size, file);
    fclose(file);
}

size_t get_file_size(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return 0;
    }
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fclose(file);
    return size;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <element_count>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    size_t element_count = atoi(argv[2]);
    int *array = malloc(element_count * sizeof(int));
    if (!array) {
        perror("Memory allocation failed");
        return 1;
    }

    FILE *csv = fopen("measurements.csv", "w");
    fprintf(csv, "ElementCount,GenerationTime,WriteTime,FileSize\n");

    for (size_t n = 1000; n <= element_count; n += 1000) {
        clock_t start_gen = clock();
        generate_random_numbers(array, n);
        clock_t end_gen = clock();
        double gen_time = (double)(end_gen - start_gen) / CLOCKS_PER_SEC;

        clock_t start_write = clock();
        write_to_file(filename, array, n);
        clock_t end_write = clock();
        double write_time = (double)(end_write - start_write) / CLOCKS_PER_SEC;

        size_t file_size = get_file_size(filename);

        fprintf(csv, "%zu,%.6f,%.6f,%zu\n", n, gen_time, write_time, file_size);
        printf("%zu elements: Gen %.6fs, Write %.6fs, Size %zu bytes\n", n, gen_time, write_time, file_size);
    }

    fclose(csv);
    free(array);
    printf("Measurement results saved to measurements.csv\n");

    return 0;
}
