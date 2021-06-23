#pragma once

#include <cstdint>

void clear_display();
void ret();
void call(uint16_t address);
void jump(uint16_t address);
void skip();

uint16_t get_rand();

void get_char(uint8_t character);

void draw(uint8_t x, uint8_t y, uint8_t height);

bool key_state(uint8_t key);

uint16_t read_key();

void store_bcd(uint8_t number);

void reg_dump(uint16_t last);

void reg_load(uint16_t last);
