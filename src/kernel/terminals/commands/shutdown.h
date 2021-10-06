class ShutdownCMD{
    public:
        static void exec();

        struct info{
            static const char* desc;
            static const char* name;
            static const bool deprecated = false;
        };
};