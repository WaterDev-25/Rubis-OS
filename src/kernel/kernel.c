extern void loader_main(){
    for(int i = 0; i < 26; i++){
        char c = 0x41 + i;

        asm(
            "mov %0, %%al;"
            "mov $0x0E, %%ah;"
            "int $0x10"
            :
            : "r" (c)
        );
    }
}