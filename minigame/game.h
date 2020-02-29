#ifndef GAME_h
#define GAME_h

void init(uint8_t* level, int x, int y);
void draw(void);
void logic(void);
void start(void);
int checkbounds(int x, int y);

typedef struct position
{
    int x;
    int y;
} position;
#endif