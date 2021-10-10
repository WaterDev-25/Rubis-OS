double sqrt(double x){ //problem?
    double res;
    asm("fsqrt" : "=t" (res) : "0" (x));
    return res;
}

int abs(int n){
    if(n>=0)
        return n;
    else
        return -1*n;
}