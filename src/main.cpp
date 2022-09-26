#include "systemc.h"
#include "genetic.h"

#define PERIOD 20

int sc_main(int argc, char* argv[]) {
  sc_signal<bool> reset;
  sc_signal<CHROMOSOME> best;
  sc_clock clk("clk", PERIOD, SC_NS, 0.5, 2, SC_NS);
  genetic g("genetic");
  g.clk(clk);
  g.reset(reset);
  g.best(best);
  srand(time(0));
  sc_start(0, SC_NS);
  reset = true;
  sc_start(PERIOD, SC_NS);
  reset = false;
  sc_start(PERIOD, SC_NS);
  CHROMOSOME b = best.read();
  int count = 0;
  int step = 0;
  while(count != CONVERG_VALUE) {
    sc_start(PERIOD, SC_NS);
    std::cout << "step: " << step++ << " best: " << b << endl;
    if(!(best.read() ^ b).or_reduce()) {
      count++;
      continue;
    }
    count = 0;
    b = best.read();
  }
  std::cout << b << endl;
  return 0;
}