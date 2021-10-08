/*
all function of the os:
-shutdown
-reboot
...
*/

class syscall {
    private:
        /* data */
    public:
        static void shutdown();
        static void reboot();
        static void halt();
};