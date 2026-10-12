// src/alu.h
#ifndef ALU_H
#define ALU_H

#include <cstdint>

struct ALUResult {
    uint32_t result;
    bool zero;
};

class ALU {
public:
    static ALUResult execute(uint32_t op1, uint32_t op2, uint8_t aluOp);
};

#endif