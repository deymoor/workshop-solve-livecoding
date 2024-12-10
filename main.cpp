#include <cstdlib>
#include <fstream>
#include <iostream>

#include "DoublyLinkedList.h"
#include "MyString.h"
#include "parser.h"


bool is_skip(char ch) {
    return ch == ' ' || ch == '\n';
}


std::istream& operator>>(std::istream& input, char (&ptr)[DoublyLinkedList::kMaxWordLen + 1]) {
    while (input && is_skip(input.peek())) {
        input.get();
    }

    size_t i = 0;
    while (input && !is_skip(input.peek())) {
        ptr[i] = input.get();
        ++i;
    }

    ptr[i] = '\0';

    return input;
}


int main(int argc, char** argv) {
    ParseResult parse_result = parse(argc, argv);
    if (parse_result.is_err) {
        return EXIT_FAILURE;
    }
    
    std::ifstream file(parse_result.args.path);

    if (!file) {
        std::cerr << "File doesn't exist" << std::endl;
        return EXIT_FAILURE;
    }

    DoublyLinkedList list;
    char word[DoublyLinkedList::kMaxWordLen + 1];
    while (file >> word) {
        list.push_back(word);
    }

    list.sort();
    list.print(parse_result.args.top_count);

    return EXIT_SUCCESS;
}
