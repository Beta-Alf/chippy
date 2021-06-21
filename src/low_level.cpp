
#include "low_level.hpp"
#include "memory.hpp"
#include <cstring>
#include <cassert>

void clear_display(){
    std::memset(screen, 0, SCREEN_SIZE);
}

void ret(){
    assert(current_level > 0);
    current_level--;
    pc = stack[current_level]
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

void draw(uint16_t x, uint16_t y, uint16_t height){
    // TODO
}

bool key_state(uint16_t key){
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


