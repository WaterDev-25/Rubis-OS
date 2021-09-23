double sqrt(double x){ //problem?
    double res;
    asm("fsqrt" : "=t" (res) : "0" (x));
    return res;
}