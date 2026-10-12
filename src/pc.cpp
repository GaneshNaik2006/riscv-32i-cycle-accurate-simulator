#include "pc.h"


ProgramCounter::ProgramCounter(){
    pc=0;
}
// Line 3: Initializes the hardware register `pc` to address 0 on boot.

uint32_t ProgramCounter::getNextPC() const { 
    return pc + 4; 
}
// Line 5-7: Calculates the next sequential instruction address. 
// Since RISC-V instructions are 4 bytes (32 bits) wide, every step advances PC by 4.


