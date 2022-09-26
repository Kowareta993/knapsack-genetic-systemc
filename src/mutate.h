#ifndef MUTATE
#define MUTATE

#include "systemc.h"
#include "properties.h"

SC_MODULE (mutate) {
    sc_in<bool> clk;
    sc_in<CHROMOSOME> in;
    sc_out<CHROMOSOME> out;

    void process();

    SC_CTOR (mutate) {
        SC_CTHREAD(process, clk.pos());
    }
};

#endif