void* memset(void* dest, unsigned char val, int count){
    unsigned char* destC = (unsigned char*)dest;
    int i;
    for(i = 0; i < count; i++)
        destC[i] = val;
    return dest;
}

void memcpy(unsigned char* source, unsigned char* dest, int count){
    for(int i = 0; i < count; i++)
        *(dest + i) = *(source + i);
}