#include <stdio.h>
#include <math.h>

#define TOTAL_TASKS 3000
#define G1_SPEED 10
#define G2_SPEED 5
#define TRANSFER_TIME 2
#define RETURN_TIME 2

int main() {
    int optimal_G1_tasks, optimal_G2_tasks;
    int min_time = 1e9;

    int optimal_x = round((double)TOTAL_TASKS * G1_SPEED / (G1_SPEED + (TRANSFER_TIME + G2_SPEED + RETURN_TIME)));
    optimal_G2_tasks = optimal_x;
    optimal_G1_tasks = TOTAL_TASKS - optimal_G2_tasks;

    int G1_time = optimal_G1_tasks * G1_SPEED;
    int G2_time = optimal_G2_tasks * (TRANSFER_TIME + G2_SPEED + RETURN_TIME);
    min_time = (G1_time > G2_time) ? G1_time : G2_time;

    printf("Optimalis feladatmegosztas:\n");
    printf("G1 megoldott feladatok: %d\n", optimal_G1_tasks);
    printf("G2 megoldott feladatok: %d\n", optimal_G2_tasks);
    printf("Minimalis befejezesi ido: %d masodperc\n", min_time);
    
    return 0;
}
