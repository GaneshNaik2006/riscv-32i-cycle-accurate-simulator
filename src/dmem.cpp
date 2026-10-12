// src/dmem.cpp
#include "dmem.h"
#include <iostream>

using namespace std;

DataMemory::DataMemory(size_t size) : memory(size, 0) {}

uint32_t DataMemory::access(uint32_t address, uint32_t writeData, bool memRead, bool memWrite) {
    if (memRead && memWrite) {
        cout << "Error: Invalid operation!" << endl;
        return 0;
    }
    if (memWrite) {
        memory[address]     = writeData & 0xFF;
        memory[address + 1] = (writeData >> 8) & 0xFF;
        memory[address + 2] = (writeData >> 16) & 0xFF;
        memory[address + 3] = (writeData >> 24) & 0xFF;
        return 0;
    }
    if (memRead) {
        return memory[address] |
              (memory[address + 1] << 8) |
              (memory[address + 2] << 16) |
              (memory[address + 3] << 24);
    }
    return 0;
}