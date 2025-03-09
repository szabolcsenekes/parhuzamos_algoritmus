#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int num1 = 1 + rand() % 100;
    int num2 = 1 + rand() % 100;
    int user_answer;

    printf("What is %d + %d?\n", num1, num2);

    time_t start_time = time(NULL);
    scanf("%d", &user_answer);
    time_t end_time = time(NULL);

    int correct_answer = num1 + num2;

    if (user_answer == correct_answer) {
        printf("Correct! The answer is: %d\n", correct_answer);
    } else {
        printf("Incorrect. The correct answer is: %d\n", correct_answer);
    }

    printf("Time taken: %ld seconds\n", end_time - start_time);

    return 0;
}
