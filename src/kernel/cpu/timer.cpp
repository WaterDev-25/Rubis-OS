int timer_ticks = 0;
int seconds = 0;

void timer_phase(int hz){
    int divisor = 1193180 / hz;
    outb(0x43, 0x36);
    outb(0x40, divisor & 0xFF);
    outb(0x40, divisor >> 8);
}

void timer_handler(struct regs *r){
    timer_ticks++;

    if(timer_ticks % 18 == 0){
        seconds++;
    }
}

void sleep(int ticks){
    int startTicks = timer_ticks;
    while(timer_ticks < startTicks + ticks){}
    return;
}

void timer_install(){
    irq_install_handler(0, timer_handler);
}