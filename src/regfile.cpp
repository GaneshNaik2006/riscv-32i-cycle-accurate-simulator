// src/regfile.cpp
#include "regfile.h"

using namespace std;

RegisterFile::RegisterFile() {
    for (int i = 0; i < 32; i++) {
        registers[i] = 0;
    }
}

void RegisterFile::read(uint8_t rs1, uint8_t rs2, uint32_t &readData1, uint32_t &readData2) const {
    readData1 = (rs1 == 0) ? 0 : registers[rs1 & 0x1F];
    readData2 = (rs2 == 0) ? 0 : registers[rs2 & 0x1F];
}

void RegisterFile::write(uint8_t rd, uint32_t writeData, bool regWrite) {
    if (regWrite && (rd != 0)) {
        registers[rd & 0x1F] = writeData;
    }
}