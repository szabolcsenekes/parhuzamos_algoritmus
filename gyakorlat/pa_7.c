#include <stdio.h>
#include <stdlib.h>

void write_int_array_to_file(const char *filename, int *array, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fwrite(array, sizeof(int), size, file);
    fclose(file);
}

void write_long_array_to_file(const char *filename, long *array, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fwrite(array, sizeof(long), size, file);
    fclose(file);
}

void write_float_array_to_file(const char *filename, float *array, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fwrite(array, sizeof(float), size, file);
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

void read_int_array_from_file(const char *filename, int *array, size_t size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fread(array, sizeof(int), size, file);
    fclose(file);
}

void read_long_array_from_file(const char *filename, long *array, size_t size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fread(array, sizeof(long), size, file);
    fclose(file);
}

void read_float_array_from_file(const char *filename, float *array, size_t size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fread(array, sizeof(float), size, file);
    fclose(file);
}

int main() {
    int int_array[] = {1, 2, 3, 4, 5};
    long long_array[] = {1000000000, 2000000000, 3000000000};
    float float_array[] = {1.1, 2.2, 3.3};

    write_int_array_to_file("int_data.bin", int_array, 5);
    write_long_array_to_file("long_data.bin", long_array, 3);
    write_float_array_to_file("float_data.bin", float_array, 3);

    printf("int_data.bin size: %zu bytes\n", get_file_size("int_data.bin"));
    printf("long_data.bin size: %zu bytes\n", get_file_size("long_data.bin"));
    printf("float_data.bin size: %zu bytes\n", get_file_size("float_data.bin"));

    int read_ints[5];
    long read_longs[3];
    float read_floats[3];

    read_int_array_from_file("int_data.bin", read_ints, 5);
    read_long_array_from_file("long_data.bin", read_longs, 3);
    read_float_array_from_file("float_data.bin", read_floats, 3);

    return 0;
}
