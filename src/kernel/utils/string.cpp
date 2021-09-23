bool StringStartsWith(const char* s, const char* t){ //temp function
    const char* g = t;
	
	bool res = true;
	int i = 0;
	do{
		if(s[i] != t[i] || i > 80){
			res = false;
			break;
		}
		else i++;
	}while(g[i] != 0);
	return res;
}

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