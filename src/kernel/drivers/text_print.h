#ifndef TEXT_PRINT_H
#define TEXT_PRINT_H
void SetCursorPosition(uint16_t position);
uint16_t PositionFromCoords(uint8_t x, uint8_t y);
void printstr(const char* str);
void printchr(char chr);
//uint16_t get_cursor_position(void);
#endif