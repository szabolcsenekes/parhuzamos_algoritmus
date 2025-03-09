#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 100000

// Függvény az egyediség ellenőrzésére
bool is_unique(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return false; // Duplikáció található
            }
        }
    }
    return true;
}

// Véletlen számokkal feltölti a tömböt, 50% eséllyel duplikációkat generálva
void generate_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (2 * size); // Nagyobb tartomány, hogy csökkentse az ütközéseket
    }
    if (rand() % 2 == 0) { // 50% eséllyel duplikáció hozzáadása
        int duplicates = size / 10; // Az elemek 10%-át duplikáljuk
        for (int i = 0; i < duplicates; i++) {
            int index1 = rand() % size;
            int index2 = rand() % size;
            arr[index2] = arr[index1];
        }
    }
}

int main() {
    srand(time(NULL));
    int sizes[] = {1, 10, 1000, 5000, 10000, 50000, 100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    for (int k = 0; k < num_sizes; k++) {
        int size = sizes[k];
        int *arr = malloc(size * sizeof(int));
        if (!arr) {
            perror("Memory allocation failed");
            return EXIT_FAILURE;
        }
        
        generate_array(arr, size);
        clock_t start = clock();
        bool unique = is_unique(arr, size);
        clock_t end = clock();
        
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("N = %d, Unique: %s, Time: %f seconds\n", size, unique ? "Yes" : "No", time_taken);
        
        free(arr);
    }
    return 0;
}
