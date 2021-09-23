#ifndef TEXT_PRINT_H
#define TEXT_PRINT_H
#include "../utils/color_codes.h"
void SetCursorPosition(uint16_t position);
uint16_t PositionFromCoords(uint8_t x, uint8_t y);
void printstr(const char* str, uint8_t color = BACKGROUND_BLACK | FOREGROUND_WHITE);
void printchr(char chr, uint8_t color = BACKGROUND_BLACK | FOREGROUND_WHITE);
void backspace(); // test func
bool StringStartsWith(const char* s, const char* t);
//uint16_t cursor_pos();
#endif