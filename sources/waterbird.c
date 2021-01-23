#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 256

static int stack[STACK_SIZE];

/** Opcodes defined in this enum */
typedef enum {
  HLT, //  0 -- hlt
  PSH, //  1 -- psh
  POP, //  2 -- pop
  ADD, //  3 -- add
  MUL, //  4 -- mul
  DIV, //  5 -- div
  SUB, //  6 -- sub
  SLT, //  7 -- slt reg_a, reg_b
  MOV, //  8 -- mov reg_a, reg_b
  SET, //  9 -- set reg, val
  LOG, // 10 -- log a
  IF,  // 11 -- if val reg ip
  IFN, // 12 -- ifn reg val ip
  GLD, // 13 -- gld reg
  GPT, // 14 -- gpt reg
  NOP  // 15 -- nop
} Opcodes;

/** Define Registers in here */
typedef enum {
  A, B, C, D, // General purpose regs
  E, F, I, J, // General purpose regs
  EX, EXA,    // Excess registers
  IP,         // Instruction pointer
  SP,         // Stack pointer
  REG_SIZE    // Registers size max 256
} Registers;

int main(int argc, char *argv[]) {
  if (argv != 2) {
    printf("Err: Too less args");
  }
  
  return 0;
}
