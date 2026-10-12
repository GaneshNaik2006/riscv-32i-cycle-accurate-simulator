// src/regfile.h
#ifndef REGFILE_H
#define REGFILE_H

#include <cstdint>

class RegisterFile {
private:
    uint32_t registers[32];
public:
    RegisterFile();
    void read(uint8_t rs1, uint8_t rs2, uint32_t &readData1, uint32_t &readData2) const;
    void write(uint8_t rd, uint32_t writeData, bool regWrite);
};

#endif