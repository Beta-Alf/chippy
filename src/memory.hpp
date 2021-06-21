#pragma once

#include <cstdint>
uint8_t ram[0x1000];

constexpr uint16_t SCREEN_SIZE = 64*32/8;
uint8_t screen[SCREEN_SIZE];


uint8_t regs[0xF];
uint16_t i;

uint16_t stack[24];
uint8_t current_level = 0;

uint16_t delay;
uint16_t sound;

uint16_t pc;
