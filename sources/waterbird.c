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
  IF,  // 11 -- if  val reg ip
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

static int registers[REG_SIZE];
/** Define Instructions array */
int *instructions;
/** How many instrs to do, init to 0 */
int instruction_count = 0;
/** Initial 4 instructions space alloc */
int instruction_space = 4;
/** Set program status. True by default */
static bool running = true;
/** Check if IP is assigned by jmp like ops */
bool is_jmp = false;

/** Quick and dirty way to get SP and IP */
#define SP (registers[SP])
#define IP (registers[IP])

/** Fetch the current Instruction set */
#define FETCH (instructionsIP])

int main(int argc, char *argv[]) {
  if (argv != 2) {
    printf("Err: Too less args");
  }
  
  return 0;
}
