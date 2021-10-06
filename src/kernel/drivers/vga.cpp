#include "port_io.h"
#include "../utils/typedefs.h"
#include "../utils/color_codes.h"
#include "../maths/vec2.h"
#include "../memory/mem.h"
#define VGA_MEMORY (uint8_t*)0xb8000
#define VGA_WIDTH 80

uint16_t CursorPosition;

void SetCursorPosition(uint16_t position){
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t)(position & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t)((position >> 8) & 0xFF));

    CursorPosition = position;
}

uint16_t PositionFromCoords(uint8_t x, uint8_t y){
    return y * VGA_WIDTH + x;
}

void printstr(const char* str, uint8_t color = BACKGROUND_BLACK | FOREGROUND_WHITE){
    uint8_t* charPtr = (uint8_t*)str;
    uint16_t index = CursorPosition;
    while(*charPtr != 0){
        switch(*charPtr){
            case 10:
                index += VGA_WIDTH;
                break;
            case 13:
                index -= index % VGA_WIDTH;
                break;
            default:
                *(VGA_MEMORY + index * 2) = *charPtr;
                *(VGA_MEMORY + index * 2 + 1) = color;
                index++;
        }
        charPtr++;
    }
    SetCursorPosition(index);
}

void printchr(char chr, uint8_t color = BACKGROUND_BLACK | FOREGROUND_WHITE){
    *(VGA_MEMORY + CursorPosition * 2) = chr;
    *(VGA_MEMORY + CursorPosition * 2 + 1) = color;

    SetCursorPosition(CursorPosition + 1);
}

void backspace(int n){
    SetCursorPosition(CursorPosition - n);
    printchr(' ');
    SetCursorPosition(CursorPosition - n);
}

void colline(int line, int col){
	for(int i = (int)VGA_MEMORY + VGA_WIDTH * 2 * line + 1; i < (int)VGA_MEMORY + VGA_WIDTH * 2 * (line + 1) + 1; i += 2) *((char*)i) = col;
}

void enable_cursor(uint8_t cursor_start, uint8_t cursor_end){
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
 
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}

void disable_cursor(){
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

void clear(int col) { //expiremental
    if(col == -1) col = 0x00;
		
	for(int i = (int)VGA_MEMORY + 160; i < (int)VGA_MEMORY + 3840; i += 1) {
		if(i % 2 == 0) *((char*)i) = 32;
		else *((char*)i) = col;
	}
}