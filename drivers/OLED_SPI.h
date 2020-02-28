// Buffers
char    textbuffer [4][16]; 
uint8_t screen_buffer[4 * 128];// 4 pages, each with 4 rows of 32 8-bit columns 

// Display Data Transfer
uint8_t spi_send_recv(uint8_t data);
void display_init(void);
void display_write(void);

void display_clear(void);


// Display Buffer Write
void load_image(const uint8_t* data);
void load_string(int line, char* s);

void buffer_clear(void);


