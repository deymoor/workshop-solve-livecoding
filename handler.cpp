#include <fstream>
#include <iostream>
#include <sstream>

#include "handler.h"
#include "DoublyLinkedList.h"
#include "parser.h"


bool is_skip(char ch) {
    return ch == ' ' || ch == '\n';
}

std::istream& operator>>(std::istream& input, char (&ptr)[1025]) {
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

bool handle(const Arguments& args) {
    std::ifstream file(args.path);

    if (!file) {
        std::cerr << "File doesn't exist" << std::endl;
        return true;
    }

    DoublyLinkedList list;
    char word[1025];
    while (file >> word) {
        list.push_back(word);
    }

    list.sort();
    list.print(args.top_count);

    return false;
}
