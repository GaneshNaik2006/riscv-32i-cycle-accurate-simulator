// src/datapath.h
#ifndef DATAPATH_H
#define DATAPATH_H

#include "pc.h"
#include "imem.h"
#include "regfile.h"
#include "immgen.h"
#include "alu.h"
#include "dmem.h"
#include "control.h"

class Datapath {
public:
    ProgramCounter pc;
    InstructionMemory imem;
    RegisterFile rf;
    DataMemory dmem;
    ControlUnit control;

    void step();
};

#endif