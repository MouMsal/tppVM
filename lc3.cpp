#include <iostream>


enum
{
    reg_R0 = 0,
    reg_R1,
    reg_R2,
    reg_R3,
    reg_R4,
    reg_R5,
    reg_R6,
    reg_R7,
    reg_PC,
    reg_COND,
    reg_COUNT
};

enum opcodes {

    ADD = 0, //add
    AND,     //bitwise and
    NOT,     //bitwise not
    LD,      //load
    LDI,     //load indirect
    LDR,     //load register
    LEA,     //load effective address
    ST,      //store
    STR,     //store register
    STI,     //store indirect
    BR,      //branch
    JMP,     //jump
    JSR,     //jump register
    RTI,     //unused
    RES,     //reserved
    TRAP    //execute trap
};

enum
{
    POS = 1 << 0, /* Positive Flag */
    ZRO = 1 << 1, /* Zero Flag */
    NEG = 1 << 2, /* Negative Flag */
};

class Memory{

};



uint16_t memory[1<<16];
uint16_t registers[reg_COUNT];

class CPU{
private:

public:

    int fetchInstruction(){
    std::cout<<"\nFetched"<<registers[reg_PC];
    return memory[registers[reg_PC]++]; //Returns the next instruction after incrementing the program counter.
    }
    void decodeInstruction(uint16_t instr){
    uint16_t opcode = instr >> 12; //Extracting opcode from the instruction
            switch (opcode)
            {
                case ADD: {
                    uint16_t r0 = (instr >> 9) & 0x7; //Extract Destination Register by shifting and masking.
                    uint16_t r1 = (instr >> 6)& 0x7; //Extract first operand by shifting and masking.

                    if(((instr >> 5) & 0x1)){ //Immediate Mode (Should I make a flag variable here?
                        //Write Later
                    }
                    else{
                        uint16_t r2 = instr & 0x7; //Second Operand
                        registers[r0] = registers[r1] + registers[r2];
                    }
                    //Update Flag
                }
                    break;
                case AND: {
                    uint16_t r0 = (instr >> 9) & 0x7;
                    uint16_t r1 = (instr >> 6)& 0x7;

                    if(((instr >> 5) & 0x1)){

                    }
                    else{

                    }

                }
                    break;
                case NOT:
                    break;
                case LD:

                    break;
                case LDI:

                    break;
                case LDR:

                    break;
                case LEA:

                    break;
                case ST:

                    break;
                case STI:

                    break;
                case STR:

                    break;
                case BR:

                    break;
                case JMP:

                    break;
                case JSR:

                    break;
                case TRAP:

                    break;
                case RTI:
                    break;
                case RES:
                    break;
                default:
                    break;
            }
}

    void loadInstruction(){
    }
};



CPU cpu;

int main() {

    registers[reg_COND] = ZRO;
    registers[reg_PC] = 0x3000; //Note to self: Make variable for 0x3000 default starting

    while(1){ //Note to self: Make variable for 1,  running
        uint16_t instr = cpu.fetchInstruction();
        cpu.decodeInstruction(instr);
    }
    return 0;
}
