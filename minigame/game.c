#include <stdint.h>
#include "../drivers/OLED_SPI.h"
#include "../drivers/input.h"
#include "levels.h"
#include "game.h"


uint8_t* _level;
position p;

void init(uint8_t* level, int x, int y) {
    _level = level;
    p.x = x;
    p.y = y;
}

void draw(void) {
    load_image(_level);
    set_pixel(p.x, p.y);
}

int checkbounds(int x, int y) {
    if (x < 0 || x > 127 || y < 0 || y > 32) return 0;
    
    uint8_t column = _level[(y / 8) * 128 + x];
    return !(column & (1 << y % 8));
}

void logic(void) {
    switch (BTNA_VAL) {
        case BTN1: if (checkbounds(p.x + 1, p.y)) p.x++;
            break;
        case BTN2: if (checkbounds(p.x, p.y + 1)) p.y++;
            break;
        case BTN3: if (checkbounds(p.x, p.y - 1)) p.y--;
            break;
        case BTN4: if (checkbounds(p.x - 1, p.y)) p.x--;
            break;
    }
    
}

void start(void) {

}