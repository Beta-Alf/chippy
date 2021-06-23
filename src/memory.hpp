#pragma once

#include <cstdint>


extern uint8_t ram[0x1000];

constexpr uint16_t SCREEN_SIZE = 64*32/8;
extern uint8_t screen[SCREEN_SIZE];


extern uint8_t regs[0xF];
extern uint16_t i;

extern uint16_t stack[24];
extern uint8_t current_level;

extern uint16_t delay;
extern uint16_t sound;

extern uint16_t pc;
