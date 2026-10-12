// src/dmem.h
#ifndef DMEM_H
#define DMEM_H

#include <vector>
#include <cstdint>
#include <cstddef>

class DataMemory {
private:
    std::vector<uint8_t> memory;
public:
    DataMemory(std::size_t size = 1024);
    uint32_t access(uint32_t address, uint32_t writeData, bool memRead, bool memWrite);
};

#endif