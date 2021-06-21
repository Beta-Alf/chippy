#include <cstdint>

void clear_display();
void ret();
void call(uint16_t address);
void jump(uint16_t address);
void skip();

uint16_t get_rand();

void draw(uint16_t x, uint16_t y, uint16_t height);

bool key_state(uint16_t key);

uint16_t read_key();

void store_bcd(uint16_t number);

void reg_dump(uint16_t last);

void reg_load(uint16_t last);
