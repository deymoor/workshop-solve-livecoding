#include <iostream>

#include "DoublyLinkedList.h"


DoublyLinkedList::DoublyLinkedList() {
    begin->next = end;
    end->prev = begin;
}

void DoublyLinkedList::push_back(const char* word_ptr) {
    BaseNode* node = begin->next;

    while (node != end) {
        Node* real_node = (Node*)node;

        if (strcmp(real_node->word, word_ptr) == 0) {
            ++real_node->count;
            return;
        }

        node = node->next;
    }

    Node* new_node = new Node(word_ptr);
    BaseNode* prev_end = end->prev;

    new_node->prev = prev_end;
    new_node->next = end;

    end->prev = new_node;
    prev_end->next = new_node;

    ++_sz;
}

void DoublyLinkedList::print(size_t node_count) const {
    BaseNode* node = begin->next;

    while (node != end && node_count) {
        Node* real_node = (Node*)node;

        char* word_ptr = real_node->word;
        while (*word_ptr != '\0') {
            std::cout << *word_ptr;
            ++word_ptr;
        }

        std::cout << ' ' << real_node->count << std::endl;

        node = node->next;
        --node_count;
    }
}

void DoublyLinkedList::sort() {
    for (size_t i = 0; i < _sz; ++i) {
        bool is_swapped = false;

        BaseNode* cur_node = begin->next;
        while (cur_node != end) {
            BaseNode* next_node = cur_node->next;
            if (next_node == end) {
                break;
            }

            Node* real_cur_node = (Node*)cur_node;
            Node* real_next_node = (Node*)next_node;

            if (real_cur_node->count < real_next_node->count) {
                std::swap(real_cur_node->word, real_next_node->word);
                std::swap(real_cur_node->count, real_next_node->count);

                is_swapped = true;
            }

            cur_node = next_node;
        }

        if (!is_swapped) {
            return;
        }
    }
}

DoublyLinkedList::~DoublyLinkedList() {
    BaseNode* node = begin;
    while (node) {
        BaseNode* next_node = node->next;
        delete node;
        node = next_node;
    }
}
