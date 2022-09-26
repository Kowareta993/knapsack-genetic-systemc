#ifndef CROSSOVER
#define CROSSOVER

#include "systemc.h"
#include "properties.h"

SC_MODULE (crossover) {
    sc_in<bool> clk;
    sc_in<CHROMOSOME> parent1;
    sc_in<CHROMOSOME> parent2;
    sc_out<CHROMOSOME> child1;
    sc_out<CHROMOSOME> child2;

    void process();

    SC_CTOR (crossover) {
        SC_CTHREAD(process, clk.pos());
    }
};

#endif