#include <stdint.h>
#include "../drivers/OLED_SPI.h"
#include "../drivers/input.h"
#include "levels.h"
#include "game.h"


uint8_t* _level;
position* p;
position* g;
uint8_t btnPressed = 0;


void init(uint8_t* level, position* player, position* goal) {
    _level = level;
    p = player;
    g = goal;
}

void draw(void) {
    load_image(_level);
    
    set_pixel(p->x, p->y);

    int x, y;
    for (y = -1; y < 2; y++){
        for (x = -1; x < 2; x++) {
            if (y == 0 && x == 0)
                continue;
            
            set_pixel(g->x + x, g->y + y);
        }
    }
}

int checkbounds(int x, int y) {
    if (x < 0 || x > 127 || y < 0 || y > 32) return 0;
    
    uint8_t column = _level[(y / 8) * 128 + x];
    return (column & (1 << y % 8));
}

void logic(void) {
    if (btnPressed) return;

    switch (BTNA) {
        case 0x1: if (checkbounds(p->x + 1, p->y)) p->x++;
            break;
        case 0x2: if (checkbounds(p->x, p->y + 1)) p->y++;
            break;
        case 0x4: if (checkbounds(p->x, p->y - 1)) p->y--;
            break;
        case 0x8: if (checkbounds(p->x - 1, p->y)) p->x--;
            break;
    }

    if (p->x = g->x && p->y == g->y) {
        // goal logic
    }

    btnPressed = 1;
}

void game(void) {

}