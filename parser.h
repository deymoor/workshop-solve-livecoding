#pragma once
#include <cstddef>

struct Arguments {
    static const int kCmdCount = 5;

    char* path = nullptr;
    size_t top_count = 0;
};

struct ParseResult {
    Arguments args;
    bool is_err = true;
};

ParseResult parse(int argc, char** argv);
