// src/control.cpp
#include "control.h"

using namespace std;

ControlSignals ControlUnit::decode(uint32_t instruction) {
    ControlSignals cs = {false, false, false, false, false, false, 0, 0};

    uint8_t opcode = instruction & 0x7F;
    uint8_t funct3 = (instruction >> 12) & 0x07;
    uint8_t funct7 = (instruction >> 25) & 0x7F;

    switch (opcode) {
        case 0x33: // R-type (add, sub, and, or)
            cs.regWrite = true;
            cs.aluSrc = false;
            if (funct3 == 0x0) {
                cs.aluOp = (funct7 == 0x20) ? 1 : 0; // 1: SUB, 0: ADD
            } else if (funct3 == 0x7) {
                cs.aluOp = 2; // AND
            } else if (funct3 == 0x6) {
                cs.aluOp = 3; // OR
            }
            break;

        case 0x13: // I-type (addi)
            cs.regWrite = true;
            cs.aluSrc = true;
            cs.aluOp = 0; // ADD
            cs.immType = 0;
            break;

        case 0x03: // Load (lw)
            cs.regWrite = true;
            cs.aluSrc = true;
            cs.memRead = true;
            cs.memToReg = true;
            cs.aluOp = 0; // Address ADD
            cs.immType = 0;
            break;

        case 0x23: // Store (sw)
            cs.memWrite = true;
            cs.aluSrc = true;
            cs.aluOp = 0; // Address ADD
            cs.immType = 1;
            break;

        case 0x63: // Branch (beq)
            cs.branch = true;
            cs.aluSrc = false;
            cs.aluOp = 1; // SUB (comparison)
            cs.immType = 2;
            break;
    }

    return cs;
}