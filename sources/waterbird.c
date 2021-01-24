#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 256

static int stack[STACK_SIZE];

/** Opcodes defined in this enum */
typedef enum {
  HALT, //  0 -- HALT
  PUSH, //  1 -- PUSH
  POP,  //  2 -- POP
  ADD,  //  3 -- ADD
  MUL,  //  4 -- MUL
  DIV,  //  5 -- DIV
  SUB,  //  6 -- SUB
  SLTR, //  7 -- SLTR   reg_a, reg_b
  MOVE, //  8 -- MOVE   reg_a, reg_b
  SET,  //  9 -- SET    reg, val
  LOG,  // 10 -- LOG    a
  IFY,  // 11 -- IFY    val reg ip
  IFN,  // 12 -- IFN    reg val ip
  LOAD, // 13 -- LOAD   reg
  GPT,  // 14 -- GPT    reg
  NOP,  // 15 -- NOP
  REM   // 16 -- REM
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
#define FETCH (instructions[IP])

/** Print the stack from A to B */
void print_stack() {
  for (int i = 0; i < SP; i++) {
    printf("0x%04d ", stack[i]);
    if ((i + 1) % 4 == 0) { printf("\n"); }
  }
  if (SP != 0) { printf("\n"); }
}

/** Print the registers all out */
void print_registers() {
  printf("Registers dump:\n ");
  // code to follow
}

/** Find empty regs in the mem */
int find_empty_registers() {
  return EX;
}

/** Evaluate the bytecode and handle errs */
void eval(int instr) {
  is_jmp = false;
  switch (instr) {
    case HALT: {
      running = false;
      printf("System halted!");
      break;
    }
    case REM: {
      continue;
    }
    case PUSH: {
      SP = SP + 1;
      IP = IP + 1;
      stack[SP] = instructions[IP];
      break;
    }
    default: {
      continue;
      /** printf("Unknown instruction: %d\n", instr); */
      /** break; */
    }
}

/** The program entrypoint */
int main(int argc, char *argv[]) {
  if (argv != 2) {
    printf("The Waterbird bytecode VM Copyright 2021 Timo Sarkar\n");
    printf("Usage: ./waterbird < foo.water >\n\n");
    return -1;
  }
  
  /** Pick fname from args */
  char *filename = argv[1];
  /** Read from fnames as arg */
  FILE *file = fopen(filename, "r");

  if (!file) {
    printf("Error: Couldn't read from file `%s`\n", filename);
    return -1;
  }

  return 0;
}
