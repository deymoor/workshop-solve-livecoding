#pragma once
#include <cstddef>

class DoublyLinkedList {
public:
    static const size_t kMaxWordLen = 1024;

    struct BaseNode {
        BaseNode* prev = nullptr;
        BaseNode* next = nullptr;
    };

    struct Node : BaseNode {
        char word[kMaxWordLen + 1];
        size_t count = 1;

        Node(const char* word_ptr);
    };

    DoublyLinkedList();

    void push_back(const char* word_ptr);
    void push_back(Node* node);
    void print(size_t node_count) const;
    void sort();

    ~DoublyLinkedList();
private:
    BaseNode* begin_ = new BaseNode();
    BaseNode* end_ = new BaseNode();

    size_t size_ = 0;
};
