// src/alu.cpp
#include "alu.h"

using namespace std;

ALUResult ALU::execute(uint32_t op1, uint32_t op2, uint8_t aluOp) {
    ALUResult res;
    switch (aluOp) {
        case 0: res.result = op1 + op2; break; // ADD
        case 1: res.result = op1 - op2; break; // SUB
        case 2: res.result = op1 & op2; break; // AND
        case 3: res.result = op1 | op2; break; // OR
        default: res.result = 0; break;
    }
    res.zero = (res.result == 0);
    return res;
}