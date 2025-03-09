#include <stdio.h>

int main() {
    int numbers[] = {123, 4567, 89, 0, 12345678};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    printf("Szóközökkel kitöltve (jobbra igazítva):\n");
    for (int i = 0; i < length; i++) {
        printf("%8d\n", numbers[i]);
    }

    printf("\nNullákkal kitöltve (jobbra igazítva):\n");
    for (int i = 0; i < length; i++) {
        printf("%08d\n", numbers[i]);
    }

    return 0;
}
