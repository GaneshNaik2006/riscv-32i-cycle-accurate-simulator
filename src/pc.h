#ifndef PC_H
#define PC_H
#include <cstdint>

class ProgramCounter {
public:
    uint32_t pc;               // Holds the 32-bit memory byte address
    ProgramCounter();          // Constructor declaration
    uint32_t getNextPC() const;// Helper to compute PC + 4
};
#endif