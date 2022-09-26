#ifndef MATLAB
#define MATLAB

#include "systemc.h"
#include "properties.h"
#include "genetic.h"

SC_MODULE (matlab) {
    sc_signal<bool> reset, clk;
    sc_signal<CHROMOSOME> best, bb;
    genetic *g;

    void process();

    SC_CTOR (matlab) {
        g = new genetic("genetic");
        g->clk(clk);
        g->reset(reset);
        g->best(best);
        
    }
};

int sc_main(int argc, char* argv[]) {
    matlab m("matlab");

    m.process();
    
    return(0);
}

#endif