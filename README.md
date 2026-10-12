# RISC-V 32I Cycle-Accurate Simulator

A modular C++ implementation of a single-cycle RISC-V processor. The project models the main datapath components and control unit, then executes instructions one step at a time while updating the program counter, registers, and data memory.

## Features

- Instruction fetch and program-counter update
- Instruction decoding and control-signal generation
- 32-register register file with `x0` fixed at zero
- Arithmetic Logic Unit (ALU)
- Immediate generation for supported instruction formats
- Instruction memory and data memory
- Load, store, arithmetic, logical, and conditional-branch operations
- Modular source files for easier testing and debugging

## Supported Instructions

| Instruction | Type | Operation |
|---|---|---|
| `add rd, rs1, rs2` | R-type | Adds two register values |
| `sub rd, rs1, rs2` | R-type | Subtracts the second register value from the first |
| `and rd, rs1, rs2` | R-type | Bitwise AND |
| `or rd, rs1, rs2` | R-type | Bitwise OR |
| `addi rd, rs1, imm` | I-type | Adds a sign-extended immediate to a register |
| `lw rd, offset(rs1)` | I-type | Loads a word from data memory |
| `sw rs2, offset(rs1)` | S-type | Stores a word in data memory |
| `beq rs1, rs2, offset` | B-type | Branches when the two register values are equal |

The simulator implements the instruction subset listed above; it is not a complete implementation of every instruction in the RV32I specification.

## Project Structure

```text
riscv-32i-cycle-accurate-simulator/
├── src/
│   ├── alu.cpp / alu.h           # Arithmetic and logical operations
│   ├── control.cpp / control.h   # Instruction decoding and control signals
│   ├── datapath.cpp / datapath.h # Fetch-decode-execute datapath
│   ├── dmem.cpp / dmem.h         # Data memory
│   ├── imem.cpp / imem.h         # Instruction memory
│   ├── immgen.cpp / immgen.h     # Immediate generation
│   ├── pc.cpp / pc.h             # Program counter
│   ├── regfile.cpp / regfile.h   # Register file
│   └── test_driver.cpp           # Component/instruction test driver
├── expected_output/
│   └── reference_run.txt         # Reference output
├── Cheat-Sheet.md                # Instruction encodings and control signals
├── Datapath_Control_Assignment.docx
└── README.md
```

## Requirements

- A C++ compiler supporting C++17, such as `g++`
- A terminal or command prompt

## Build and Run

From the project root, compile the source files:

```bash
g++ -Wall -Wextra -std=c++17 src/*.cpp -o riscv_sim
```

Run the test driver:

```bash
./riscv_sim
```

On Windows with MinGW, run the generated executable with:

```powershell
.\riscv_sim.exe
```

The test driver loads machine-code instructions into instruction memory, steps the processor, and prints the resulting register values, memory value, and branch-related program-counter update.

## How It Works

Each call to `Datapath::step()` simulates one processor cycle:

1. **Fetch:** Read the instruction at the current program counter.
2. **Decode:** Extract instruction fields and generate control signals.
3. **Register read and immediate generation:** Read source registers and construct the immediate value when required.
4. **Execute:** Perform the selected ALU operation.
5. **Memory access:** Read from or write to data memory for load/store instructions.
6. **Write-back:** Write the ALU result or loaded data into the destination register when enabled.
7. **PC update:** Advance to the next instruction or take a branch when the branch condition is satisfied.

## Testing and Debugging

- Use the included test driver to check the supported instruction operations.
- Compile with `-Wall -Wextra` to surface common compiler warnings.
- Refer to `Cheat-Sheet.md` for instruction encoding, control signals, and immediate-generation notes.
- Compare behavior with the reference output in `expected_output/reference_run.txt` where applicable.

## Limitations

- Only the instruction subset listed above is supported.
- The implementation models a single-cycle datapath; it does not implement pipelining, pipeline hazards, caches, or a complete operating-system/runtime environment.
- The supplied test driver is a focused test program, not an exhaustive verification suite.

## Learning Objectives

This project demonstrates how a processor's datapath and control unit cooperate to execute machine instructions. It is intended for learning and experimentation with computer organization, instruction formats, control signals, register operations, memory access, and program-counter behavior.