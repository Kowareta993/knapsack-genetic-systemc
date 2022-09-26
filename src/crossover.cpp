#include "crossover.h"
#include <cstdlib>

void crossover::process() {
    while(true) {
        wait();
        int index = rand() % (CHROMOSOME_LENGTH - 1) + 1;
        child1 = (parent1.read().range(CHROMOSOME_LENGTH - 1, index), parent2.read().range(index - 1, 0));
        child2 = (parent2.read().range(CHROMOSOME_LENGTH - 1, index), parent1.read().range(index - 1, 0));
    }

}
