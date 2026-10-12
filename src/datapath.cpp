// src/datapath.cpp
#include "datapath.h"
#include <iostream>

using namespace std;

void Datapath::step() {
    // 1. Fetch
    uint32_t inst = imem.read(pc.pc);

    // 2. Decode Control Signals
    ControlSignals cs = control.decode(inst);

    // Instruction Fields
    uint8_t rs1 = (inst >> 15) & 0x1F;
    uint8_t rs2 = (inst >> 20) & 0x1F;
    uint8_t rd  = (inst >> 7)  & 0x1F;

    // 3. Register Read & Immediate Gen
    uint32_t rdata1, rdata2;
    rf.read(rs1, rs2, rdata1, rdata2);
    int32_t imm = ImmediateGenerator::generate(inst, cs.immType);

    // MUX: Select ALU Operand 2
    uint32_t aluOp2 = cs.aluSrc ? imm : rdata2;

    // 4. ALU Execution
    ALUResult aluRes = ALU::execute(rdata1, aluOp2, cs.aluOp);

    // 5. Data Memory Access
    uint32_t memData = dmem.access(aluRes.result, rdata2, cs.memRead, cs.memWrite);

    // MUX: Writeback Source
    uint32_t wbData = cs.memToReg ? memData : aluRes.result;

    // 6. Register Writeback
    rf.write(rd, wbData, cs.regWrite);

    // 7. Next PC (Sequential or Branch Taken)
    bool pcSrc = cs.branch && aluRes.zero;
    if (pcSrc) {
        pc.pc = pc.pc + imm;
    } else {
        pc.pc = pc.getNextPC();
    }
}