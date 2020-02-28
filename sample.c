#include "drivers/OLED_I2C.h"
#include "drivers/OLED_SPI.h"
#include "data.h"
#include <stdint.h>

void fourlines(char r1[], char r2[], char r3[], char r4[]) {
    buffer_clear();

    load_string(0, r1);
    load_string(1, r2);
    load_string(2, r3);
    load_string(3, r4);

    display_write();
}

void threelines_and_menu(char r1[], char r2[], char r3[]) {
    buffer_clear();

    load_string(0, r1);
    load_string(1, r2);
    load_string(2, r3);

    load_image(image_menu);

    display_write();
}
