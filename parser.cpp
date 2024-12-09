#include <charconv>
#include <iostream>

#include "parser.h"

size_t get_size(char* ptr) {
    size_t size = 0;
    while (*ptr != '\0') {
        ++ptr;
        ++size;
    }
    return size;
}

ParseResult parse(int argc, char** argv) {
    ParseResult result;

    if (argc != Arguments::kCmdCount) {
        std::cerr << "Command view: ./bin --input path --top num" << std::endl;
        return result;
    }

    int cur_str = 1;
    while (cur_str != Arguments::kCmdCount) {
        if (strcmp("--input", argv[cur_str]) == 0) {
            result.args.path = argv[cur_str + 1];
        } else if (strcmp("--top", argv[cur_str]) == 0) {
            char* top_param = argv[cur_str + 1];

            size_t param_size = get_size(top_param);

            char* begin = top_param;
            char* end = top_param + param_size;

            std::from_chars_result parse_result = std::from_chars(begin, end, result.args.top_count);

            if (parse_result.ptr != end) {
                std::cerr << "--top argument must be a integer number" << std::endl;
                return result;
            } else if (parse_result.ec == std::errc::result_out_of_range) {
                std::cerr << "Too large number" << std::endl;
                return result;
            }
        } else {
            std::cerr << "Incorrect flag!" << std::endl;
            return result;
        }
        cur_str += 2;
    }

    result.is_err = false;

    return result;
}
