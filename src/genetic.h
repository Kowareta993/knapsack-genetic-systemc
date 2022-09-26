#ifndef GENETIC
#define GENETIC

#include "systemc.h"
#include "properties.h"
#include "population.h"
#include "crossover.h"
#include "mutate.h"

SC_MODULE (genetic) {
    sc_in<bool> clk;
    sc_in<bool> reset;
    sc_out<CHROMOSOME> best;
    
    
    sc_signal<bool> init;
    sc_signal<CHROMOSOME> b, sec_b, child1, child2, m_c1, m_c2;

    population *p;
    crossover *c;
    mutate *m1;
    mutate *m2;
    void process();

    SC_CTOR (genetic) {
        p = new population("population");
        c = new crossover("crossover");
        m1 = new mutate("m1");
        m2 = new mutate("m2");
        p->init(init);
        p->next(clk);
        p->best(b);
        p->second_best(sec_b);
        p->child1(m_c1);
        p->child2(m_c2);
        c->parent1(b);
        c->parent2(sec_b);
        c->child1(child1);
        c->child2(child2);
        c->clk(clk);
        m1->in(child1);
        m1->out(m_c1);
        m1->clk(clk);
        m2->in(child2);
        m2->out(m_c2);
        m2->clk(clk);
        SC_CTHREAD(process, clk.pos());
    }
};

#endif