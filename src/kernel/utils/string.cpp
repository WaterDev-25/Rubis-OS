#include "../utils/typedefs.h"

char* itoa(int res){
    int size = 0;
    int t = res;

    while(t / 10 != 0) {
        t = t/10;
        size++;
    }
    static char ret[64];
    size++;
    ret[size] = '\0';
    t = res;
    int i = size - 1;
    while(i >= 0) {
        ret[i] = (t % 10) + '0';
        t = t/10;
        i--;
    }

    return ret;
}

const char* btoa(bool res){
    const char* vOut = res ? "true": "false";
    return vOut;
}

/*
char* dtoa(double res){

}
*/

int strlen(const char* s){
    int res;
    for(res = 0; s[res] != 0; res++);
    return res;
}

int strcmp(const char *s1, const char *s2){
    while ((*s1 == *s2) && *s1) { ++s1; ++s2; }
    return ((int) (unsigned char) *s1) - ((int) (unsigned char) *s2);
}