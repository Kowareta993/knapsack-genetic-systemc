#ifndef PROPERTIES
#define PROPERTIES

#include "systemc.h"

#define CHROMOSOME_LENGTH 9
#define POPULATION_SIZE 20
#define CHROMOSOME sc_bv<CHROMOSOME_LENGTH>
#define MUTATION_P 0.2
#define MAX_WEIGHT 35
#define CONVERG_VALUE 5

float fitness(CHROMOSOME chromosome);

#endif