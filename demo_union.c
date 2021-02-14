//
// Created by 许良 on 2021/2/14.
//
#include <generic_ext.h>
#define PRINT_INT 0
#define PRINT_DOUBLE 1
#define PRINT_STRING 2

/**
 * 操作数
 */
typedef union Operand {
    int int_val;
    double double_val;
    char *char_val;
} Operand;

/**
 * 指令
 */
typedef struct Instruction {
    int operator;
    Operand operand;
} Instruction;

/**
 * 执行指令
 * @param instruction
 */
void ExecuteInstruction(Instruction *instruction) {
    int operator = instruction->operator;
    switch (operator) {
        case PRINT_INT:
            Printlnf("%d", instruction->operand.int_val);
            break;
        case PRINT_DOUBLE:
            Printlnf("%f", instruction->operand.double_val);
            break;
        case PRINT_STRING:
            Printlnf("%s", instruction->operand.char_val);
            break;
        default:
            // do nothing
            break;
    }
}

int main() {
    Printlnf("Operand size : %d", sizeof(Operand));
    Instruction instruction = {.operator=PRINT_STRING, .operand={
            .char_val="Hello World !"
    }};
    ExecuteInstruction(&instruction);
    return 0;
}

