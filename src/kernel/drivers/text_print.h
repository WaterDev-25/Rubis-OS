#ifndef TEXT_PRINT_H
#define TEXT_PRINT_H
#include "../utils/color_codes.h"
void SetCursorPosition(uint16_t position);
uint16_t PositionFromCoords(uint8_t x, uint8_t y);
void printstr(const char* str, uint8_t color = BACKGROUND_BLACK | FOREGROUND_WHITE);
void printchr(char chr, uint8_t color = BACKGROUND_BLACK | FOREGROUND_WHITE);
void backspace(int n);
void colline(int line, int col);
#endif