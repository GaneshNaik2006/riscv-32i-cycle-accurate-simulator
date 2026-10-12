#include <iostream>
#include <iomanip>
#include "datapath.h"

using namespace std;

void printTestHeader(const string& instName) {
    cout << "\n==========================================" << endl;
    cout << " Testing: " << instName << endl;
    cout << "==========================================" << endl;
}

int main() {
    Datapath core;

    // --- 1. Test ADDI (I-type): addi x1, x0, 10 --- (0x00A00093)
    printTestHeader("1. addi x1, x0, 10");
    core.imem.loadInstruction(0, 0x00A00093);
    core.step();
    uint32_t dummy, x1;
    core.rf.read(0, 1, dummy, x1);
    cout << "Result: x1 = " << x1 << " (Expected: 10)" << endl;

    // --- 2. Test ADD (R-type): add x2, x1, x1 --- (0x00108133)
    printTestHeader("2. add x2, x1, x1");
    core.imem.loadInstruction(4, 0x00108133);
    core.step();
    uint32_t x2;
    core.rf.read(1, 2, x1, x2);
    cout << "Result: x2 = " << x2 << " (Expected: 20)" << endl;

    // --- 3. Test SUB (R-type): sub x3, x2, x1 --- (0x401101B3)
    printTestHeader("3. sub x3, x2, x1");
    core.imem.loadInstruction(8, 0x401101B3);
    core.step();
    uint32_t x3;
    core.rf.read(2, 3, x2, x3);
    cout << "Result: x3 = " << x3 << " (Expected: 10)" << endl;

    // --- 4. Test AND (R-type): and x4, x2, x3 --- (0x00317233)
    printTestHeader("4. and x4, x2, x3");
    core.imem.loadInstruction(12, 0x00317233);
    core.step();
    uint32_t x4;
    core.rf.read(3, 4, x3, x4);
    cout << "Result: x4 = " << x4 << " (Expected: 10)" << endl;

    // --- 5. Test OR (R-type): or x5, x2, x3 --- (0x003162B3)
    printTestHeader("5. or x5, x2, x3");
    core.imem.loadInstruction(16, 0x003162B3);
    core.step();
    uint32_t x5;
    core.rf.read(3, 5, x3, x5);
    cout << "Result: x5 = " << x5 << " (Expected: 20)" << endl;

    // --- 6. Test SW (S-type): sw x2, 4(x0) --- (0x00202223)
    printTestHeader("6. sw x2, 4(x0)");
    core.imem.loadInstruction(20, 0x00202223);
    core.step();
    uint32_t memVal = core.dmem.access(4, 0, true, false);
    cout << "Result: Mem[4] = " << memVal << " (Expected: 20)" << endl;

    // --- 7. Test LW (I-type): lw x6, 4(x0) --- (0x00402303)
    printTestHeader("7. lw x6, 4(x0)");
    core.imem.loadInstruction(24, 0x00402303);
    core.step();
    uint32_t x6;
    core.rf.read(0, 6, dummy, x6);
    cout << "Result: x6 = " << x6 << " (Expected: 20)" << endl;

    // --- 8. Test BEQ (B-type): beq x1, x3, 8 (Taken Branch) --- (0x00308463)
    printTestHeader("8. beq x1, x3, 8 (Branch Taken)");
    core.imem.loadInstruction(28, 0x00308463);
    uint32_t pcBefore = core.pc.pc;
    core.step();
    cout << "Result: PC jumped from " << pcBefore << " to " << core.pc.pc << " (Expected: 36)" << endl;

    cout << "\n=== All Assignment 2 Tests Completed Successfully! ===" << endl;
    return 0;
}