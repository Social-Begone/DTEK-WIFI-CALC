#include <stdint.h>
#include <pic32mx.h>
#include "main.h"

int getbtns (void) {
    return (((PORTD >> 4) & 0xe) | ((PORTF >> 1) & 0x1));
}
