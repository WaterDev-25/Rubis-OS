#include "port_io.h"
#include "../utils/typedefs.h"
#include "../maths/vec2.h"
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

void printstr(const char* str){
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
                index++;
        }
        charPtr++;
    }
    SetCursorPosition(index);
}

void printchr(char chr){
    *(VGA_MEMORY + CursorPosition * 2) = chr;

    SetCursorPosition(CursorPosition + 1);
}

/*
// ADD .h BIG PRBL
uint16_t get_cursor_position(void) {
    uint16_t pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((uint16_t)inb(0x3D5)) << 8;
    //return x = pos / VGA_WIDTH, y = pos % VGA_WIDTH; // IT'S JUST MEMO :)
    //return Vector2(pos / VGA_WIDTH, pos % VGA_WIDTH);
    return pos;
}
*/