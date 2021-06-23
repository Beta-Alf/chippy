#include "high_level.hpp"
#include "low_level.hpp"
#include "memory.hpp"

void loop()
{
    while(true){
        auto opcode = fetch();
        execute(opcode);
        draw();
        tick();
    }
}

uint16_t fetch(){
    return 0xFFFF;
};

// TODO: register setting on shifts

void execute(uint16_t opcode)
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
    if ((opcode & 0xF000) == 0x9000) {
        if (regs[r1] != regs[r2]) {
            skip();
        }
    }
    // SET mem pointer CONSTANT
    if ((opcode & 0xF000) == 0xA000) {
        i = cl;
    }
    // JUMP offset
    if ((opcode & 0xF000) == 0xB000) {
        pc = regs[0]+cl;
    }
    // RAND
    if ((opcode & 0xF000) == 0xC000) {
        get_rand() & cl;
    }
    // Display
    if ((opcode & 0xF000) == 0xD000) {
        draw(regs[r1], regs[r2], cs);
    }
    // KEY EQ SKIP
    if ((opcode & 0xF0FF) == 0xE09E) {
        if(key_state(regs[r1])){
            skip();
        }
    }
    // KEY NEQ SKIP
    if ((opcode & 0xF0FF) == 0xE0A1) {
        if(!key_state(regs[r1])){
            skip();
        }
    }
    // SET REG to DELAY
    if ((opcode & 0xF0FF) == 0xF007) {
        regs[r1] = delay;
    }
    // KEY READ (Blocking)
    if ((opcode & 0xF0FF) == 0xF00A) {
        regs[r1] = read_key();
    }
    // SET DELAY REG
    if ((opcode & 0xF0FF) == 0xF015) {
        delay = regs[r1];
    }
    // SET SOUND TIMER
    if ((opcode & 0xF0FF) == 0xF018) {
        sound = regs[r1];
    }
    // ADD to mem pointer
    if ((opcode & 0xF0FF) == 0xF01E) {
        i += regs[r1];
    }
    // SET mem pointer REG
    if ((opcode & 0xF0FF) == 0xF029) {
        get_char(regs[r1]);
    }
    // STORE BCD
    if ((opcode & 0xF0FF) == 0xF029) {
        store_bcd(regs[r1]);
    }
    // REG DUMP
    if ((opcode & 0xF0FF) == 0xF029) {
        reg_dump(r1);
    }
    // REG LOAD
    if ((opcode & 0xF0FF) == 0xF029) {
        reg_load(r1);
    }
    // Uh-Oh Invalid opcode
}

void tick(){
   
};

void draw(){

};
