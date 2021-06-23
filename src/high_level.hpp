#pragma once

#include <cstdint>

void loop();

uint16_t fetch();
void execute(uint16_t opcode);
void draw();
void tick();

