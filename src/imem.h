// src/imem.h
#ifndef IMEM_H
#define IMEM_H

#include <vector>
#include <cstdint>
#include <cstddef>

class InstructionMemory {
private:
    std::vector<uint32_t> memory;
public:
    InstructionMemory(std::size_t size = 1024);
    void loadInstruction(uint32_t address, uint32_t instruction);
    uint32_t read(uint32_t address) const;
};

#endif