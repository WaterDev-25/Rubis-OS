class ShutdownCMD{
    public:
        static void exec();

        struct info{
            static const char* desc;
            static const bool deprecated = false;
        };
};