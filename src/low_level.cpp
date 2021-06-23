
#include "low_level.hpp"
#include "memory.hpp"
#include <cstring>
#include <cassert>

uint8_t screen[SCREEN_SIZE];


uint8_t regs[0xF] = {};
uint16_t i = 0;

uint16_t stack[24] = {};
uint8_t current_level = 0;

uint16_t delay = 0;
uint16_t sound = 0;

uint16_t pc = 0x200;


void get_char(uint8_t character){

};

void clear_display(){
    std::memset(screen, 0, SCREEN_SIZE);
}

void ret(){
    assert(current_level > 0);
    current_level--;
    pc = stack[current_level];
}

void call(uint16_t address){
    assert(current_level < 47);
    stack[current_level] = pc;
    pc = address;
    current_level++;
}

void jump(uint16_t address){
    pc = address;
}

void skip(){
    pc++;
}

uint16_t get_rand(){
    // TODO
    return 4;
}

void draw(uint8_t x, uint8_t y, uint8_t height){
    // TODO
}

bool key_state(uint8_t key){
    // TODO
    return false;
}

uint16_t read_key(){
    // TODO
    return 0;
}

void store_bcd(uint8_t number){
    uint8_t high;
    uint8_t mid;
    uint8_t low;
}

void reg_dump(uint16_t last){

}

void reg_load(uint16_t last){

}


