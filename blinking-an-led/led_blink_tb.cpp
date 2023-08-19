#include <verilated.h>
#include "Vled_blink.h"  // Verilated module definition

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    // Create an instance of the Verilated module
    Vled_blink* top = new Vled_blink;

    // Initialize simulation variables
    int time = 0;
    int half_period = 5;  // Half of the clock period in time units
    int sim_duration = 100;  // Total simulation duration in clock cycles

    // Simulate for the specified duration
    while (time < half_period * 2 * sim_duration) {
        // Apply a clock signal
        top->clk = (time % (2 * half_period)) < half_period;

        // Evaluate the module
        top->eval();

        // Print LED status
        printf("Time %d: LED = %d\n", time, top->led);

        // Simulate the clock edge
        time++;
    }

    // Clean up
    top->final();
    delete top;

    return 0;
}
