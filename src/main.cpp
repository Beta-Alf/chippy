
#include <cstdint>

uint8_t ram[0x1000];

uint16_t regs[0xF];
uint16_t I_register;

uint16_t stack[24];

uint16_t delay_timer;
uint16_t sound_timer;

uint16_t PC;

int main()
{

    return 0;
}

void clear_display(){};
void ret(){};
void call(uint16_t address){};
void jump(uint16_t address){};
void skip(){};

void execute_opcode(uint16_t opcode)
{
    uint16_t r1 = opcode & 0x0F00 >> 8;
    uint16_t r2 = opcode & 0x00F0 >> 4;
    uint16_t ca = opcode & 0x0FFF;
    uint16_t cl = opcode & 0x00FF;
    uint16_t cs = opcode & 0x000F;
    // DISPLAY
    if (opcode == 0x00E0) {
        clear_display();
    }
    // RETURN
    if (opcode == 0x00EE) {
        ret();
    }
    // CALL machine
    if ((opcode & 0xF000) == 0x0000) {
        // TODO: unimplemented
        call(ca);
    }
    // JUMP
    if ((opcode & 0xF000) == 0x1000) {
        jump(ca);
    }
    // CALL
    if ((opcode & 0xF000) == 0x2000) {
        call(ca);
    }
    // SKIP EQ
    if ((opcode & 0xF000) == 0x3000) {
        if (regs[r1] == cl) {
            skip();
        }
    }
    // SKIP NEQ
    if ((opcode & 0xF000) == 0x4000) {
        if (regs[r1] != cl) {
            skip();
        }
    }
    // SKIP REG EQ
    if ((opcode & 0xF000) == 0x5000) {
        if (regs[r1] == regs[r2]) {
            skip();
        }
    }
    // REG set CONST
    if ((opcode & 0xF000) == 0x6000) {
        regs[r1] = cl;
    }
    // REG add CONST
    if ((opcode & 0xF000) == 0x7000) {
        regs[r1] += cl;
    }
    // REG set REG
    if ((opcode & 0xF00F) == 0x8000) {
        regs[r1] = regs[r2];
    }
    // REG bit or
    if ((opcode & 0xF00F) == 0x8001) {
        regs[r1] |= regs[r2];
    }
    // REG bit and
    if ((opcode & 0xF00F) == 0x8002) {
        regs[r1] &= regs[r2];
    }
    // REG bit xor
    if ((opcode & 0xF00F) == 0x8003) {
        regs[r1] ^= regs[r2];
    }
    // REG add REG
    if ((opcode & 0xF00F) == 0x8004) {
        regs[r1] += regs[r2];
    }
    // REG sub REG
    if ((opcode & 0xF00F) == 0x8005) {
        regs[r1] -= regs[r2];
    }
    // REG shift right
    if ((opcode & 0xF00F) == 0x8006) {
        regs[r1] = regs[r1] >> regs[r2];
    }
    // REG sub 2
    if ((opcode & 0xF00F) == 0x8006) {
        regs[r1] = regs[r2] - regs[r1];
    }
    // REG shift left
    if ((opcode & 0xF00F) == 0x800E) {
        regs[r1] = regs[r1] << regs[r2];
    }
    // SKIP REG NEQ REG
    if ((opcode & 0xF000) == 0x5000) {
        if (regs[r1] != regs[r2]) {
            skip();
        }
    }
    // SET mem pointer CONSTANT
    // JUMP
    // RAND
    // Display
    // KEY EQ SKIP
    // KEY NEQ SKIP
    // SET REG to DELAY
    // KEY READ (Blocking)
    // SET DELAY REG
    // SET SOUND TIMER
    // ADD to mem pointer
    // SET mem pointer REG
    // STORE BCD
    // REG DUMP
    // REG LOAD
}

