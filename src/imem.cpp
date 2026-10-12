// src/imem.cpp
#include "imem.h"

using namespace std;

InstructionMemory::InstructionMemory(size_t size){
    memory.assign(size,0);
}

void InstructionMemory::loadInstruction(uint32_t address, uint32_t instruction) {
    size_t index = address / 4;
    if (index < memory.size()) {
        memory[index] = instruction;
    }
}

uint32_t InstructionMemory::read(uint32_t address) const {
    size_t index = address / 4;
    return (index < memory.size()) ? memory[index] : 0;
}


