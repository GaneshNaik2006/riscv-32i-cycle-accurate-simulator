// src/immgen.cpp
#include "immgen.h"

using namespace std;

int32_t ImmediateGenerator::generate(uint32_t instruction, uint8_t immType) {
    int32_t imm = 0;
    switch (immType) {
        case 0: // I-type
            imm = static_cast<int32_t>(instruction) >> 20;
            break;
        case 1: // S-type
            imm = (((static_cast<int32_t>(instruction) >> 25) << 5) | ((instruction >> 7) & 0x1F));
            imm = (imm << 20) >> 20;
            break;
        case 2: // B-type
            imm = (((instruction >> 31) & 0x1) << 12) |
                  (((instruction >> 7)  & 0x1) << 11) |
                  (((instruction >> 25) & 0x3F) << 5) |
                  (((instruction >> 8)  & 0xF) << 1);
            imm = (static_cast<int32_t>(imm << 19)) >> 19;
            break;
    }
    return imm;
}