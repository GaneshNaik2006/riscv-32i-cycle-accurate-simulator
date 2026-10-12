// src/immgen.h
#ifndef IMMGEN_H
#define IMMGEN_H

#include <cstdint>

class ImmediateGenerator {
public:
    static int32_t generate(uint32_t instruction, uint8_t immType);
};

#endif