// src/control.h
#ifndef CONTROL_H
#define CONTROL_H

#include <cstdint>

struct ControlSignals {
    bool regWrite;
    bool aluSrc;
    bool memRead;
    bool memWrite;
    bool memToReg;
    bool branch;
    uint8_t aluOp;   // 0: ADD, 1: SUB, 2: AND, 3: OR
    uint8_t immType; // 0: I-type, 1: S-type, 2: B-type
};

class ControlUnit {
public:
    ControlSignals decode(uint32_t instruction);
};

#endif