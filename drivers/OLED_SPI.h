extern char textbuffer[4][16];
uint8_t spi_send_recv(uint8_t data);
void display_image(int x, const uint8_t *data);
void display_init(void);
void display_string(int line, char *s);
void display_update(void);