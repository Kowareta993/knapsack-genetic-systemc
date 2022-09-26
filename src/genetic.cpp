#include "genetic.h"
#include "population.h"
#include "crossover.h"
#include "mutate.h"
#include <cstdlib>

void genetic::process() {
    while(true) {
        wait();
        if(reset.read() == true) {
            init = true;
        } else {
            init = false;
            best.write(b);
        }
        
    }
}