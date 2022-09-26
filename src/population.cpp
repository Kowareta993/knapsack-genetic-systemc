#include "population.h"
#include <cstdlib>

void population::initialize() {
    for(int i = 0; i < POPULATION_SIZE; i++) {
        CHROMOSOME c;
        for(int j = 0; j < CHROMOSOME_LENGTH; j++) {
            c[j] = (rand() % 2) == 1;
        }
        p[i] = c;
    }
}



void population::next_generation() {
    p[POPULATION_SIZE-1] = child1.read();
    p[POPULATION_SIZE-2] = child2.read();
    bool changed = true;
    while(changed) {
        changed = false;
        for(int i = 0; i < POPULATION_SIZE - 1; i++) {
            if(fitness(p[i]) < fitness(p[i+1])) {
                CHROMOSOME tmp = p[i];
                p[i] = p[i+1];
                p[i+1] = tmp;
                changed = true;
            }
        }
    }
    best.write(p[0]);
    second_best.write(p[1]);
}
