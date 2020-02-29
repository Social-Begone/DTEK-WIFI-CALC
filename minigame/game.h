#ifndef GAME_h
#define GAME_h

typedef struct position
{
    int x;
    int y;
} position;

void init(uint8_t* level, position* player, position* goal);
void draw(void);
void logic(void);
void game(void);
int checkbounds(int x, int y);


#endif