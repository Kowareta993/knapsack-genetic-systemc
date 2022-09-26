#ifndef POPULATION
#define POPULATION

#include "systemc.h"
#include "properties.h"

SC_MODULE (population) {
    sc_in<bool> init;
    sc_in<bool> next;
    sc_in<CHROMOSOME> child1;
    sc_in<CHROMOSOME> child2;
    sc_out<CHROMOSOME> best;
    sc_out<CHROMOSOME> second_best;

    CHROMOSOME p [POPULATION_SIZE];

    void initialize();
    void next_generation();

    SC_CTOR (population) {
        SC_METHOD(initialize);
        sensitive << init.pos();
        
        SC_METHOD(next_generation);
        sensitive << next.pos();
        
    }
};

#endif