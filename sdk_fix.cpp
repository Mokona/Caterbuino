// Because the library for Arduino seems incomplete
namespace std {
    void __throw_bad_function_call()
    {
        while (1)
            ;
    }

    void __throw_bad_alloc()
    {
        while (1)
            ;
    }

    void __throw_length_error(const char*)
    {
        while (1)
            ;
    }
}
