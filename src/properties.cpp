#include "properties.h"

float fitness(CHROMOSOME chromosome) {
    int price[CHROMOSOME_LENGTH] = {6, 5, 8, 9, 6, 7, 3, 6, 8};
    int weight[CHROMOSOME_LENGTH] = {2, 3, 6, 7, 5, 9, 3, 4, 5};
    float score = 0;
    int w = 0;
    for (int i = 0; i < CHROMOSOME_LENGTH; i++) {
        if (chromosome[i]) {
            score += price[CHROMOSOME_LENGTH - i - 1] / float(weight[CHROMOSOME_LENGTH - i - 1]);
            w += weight[CHROMOSOME_LENGTH - i - 1];
        }
    }
    return w <= MAX_WEIGHT ? score : 0;
}