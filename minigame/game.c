#include <stdint.h>
#include "../drivers/OLED_SPI.h"
#include "../drivers/input.h"
#include "levels.h"
#include "game.h"

#define P_WIDTH 4
#define P_HEIGHT 4

const uint8_t* _level;
position g;
position p;
uint8_t exit = 0;


void init(const uint8_t* level, position player, const position goal) {
    _level = level;
    p = player;
    g = goal;
}

void draw(void) {
    buffer_clear();

    // load_image(_level);

    int x, y;
    
    for (y = 0; y < P_HEIGHT; y++)
        for (x = 0; x < P_WIDTH; x++)
            set_pixel(p.x + x, p.y + y);


    for (y = -1; y < 1 + P_HEIGHT; y++){
        for (x = -1; x < 1 + P_WIDTH; x++) {
            if (y > -1 && y < P_HEIGHT &&
                x > -1 && x < P_WIDTH)
                continue;
            
            set_pixel(g.x + x, g.y + y);
        }
    }

    display_write();
}

int checkbounds(int x, int y) {
    if (x < 0 || x > 128 - P_WIDTH || y < 0 || y > 32 - P_HEIGHT) return 0;
    
    uint8_t column = _level[(y / 8) * 128 + x];
    return (column & (1 << y % 8));
}

void logic(void) {
    switch (BTNA) {
        case 0x1: if (checkbounds(p.x + P_WIDTH, p.y)) p.x += P_WIDTH;
            break;
        case 0x2: if (checkbounds(p.x, p.y - P_HEIGHT)) p.y -= P_HEIGHT;
            break;
        case 0x4: if (checkbounds(p.x, p.y + P_HEIGHT)) p.y += P_HEIGHT;
            break;
        case 0x8: if (checkbounds(p.x - P_HEIGHT, p.y)) p.x -= P_WIDTH;
            break;
    }
    while (BTNA);
    

    if (p.x == g.x && p.y == g.y)
        exit = 1;
}

void game(void) {
    while (!exit) {
        logic();
        draw();
    }
}