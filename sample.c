#include "drivers/OLED_I2C.h"
#include "drivers/OLED_SPI.h"
#include "data.h"
#include <stdint.h>

void fourlines(void) {
    buffer_clear();

    load_string(0, "Row 1");
    load_string(1, "Row 2");
    load_string(2, "Row 3");
    load_string(3, "Row 4");

    display_write();
}

void threelines_and_menu(void) {
    buffer_clear();

    load_string(0, "Row 1");
    load_string(1, "Row 2");
    load_string(2, "Row 3");

    load_image(image_menu);

    display_write();
}