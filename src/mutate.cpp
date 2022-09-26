#include "mutate.h"
#include <cstdlib>

void mutate::process() {
    while(true) {
        wait();
        CHROMOSOME chromosome = in.read();
        if (rand() % 100 < MUTATION_P * 100) {
            int i = rand() % CHROMOSOME_LENGTH;
            chromosome[i] = ~chromosome[i];
        }
        out.write(chromosome);
    }
    
        
}
