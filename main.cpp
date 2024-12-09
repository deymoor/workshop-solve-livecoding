#include <cstdlib>
#include <iostream>

#include "handler.h"
#include "parser.h"

int main(int argc, char** argv) {
    ParseResult parse_result = parse(argc, argv);
    if (parse_result.is_err) {
        return EXIT_FAILURE;
    }
    
    bool is_err = handle(parse_result.args);
    if (is_err) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
