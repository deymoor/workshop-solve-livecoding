#pragma once
#include <cstddef>

class DoublyLinkedList {
public:
    static const size_t kMaxWordLen = 1024;
    
    DoublyLinkedList();

    void push_back(const char* word_ptr);
    void print(size_t node_count) const;
    void sort();

    ~DoublyLinkedList();
private:
    struct BaseNode {
        BaseNode* prev = nullptr;
        BaseNode* next = nullptr;
    };

    struct Node : BaseNode {
        char word[1025];
        size_t count = 1;

        Node(const char* word_ptr) {
            size_t i = 0;
            while (*word_ptr != '\0') {
                word[i] = *word_ptr;
                ++word_ptr;
                ++i;
            }
            word[i] = '\0';
        }
    };

    BaseNode* begin = new BaseNode();
    BaseNode* end = new BaseNode();

    size_t _sz = 0;
};
