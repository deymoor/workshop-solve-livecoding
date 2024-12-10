#include <iostream>

#include "DoublyLinkedList.h"


DoublyLinkedList::Node::Node(const char* word_ptr) {
    size_t i = 0;
    while (*word_ptr != '\0') {
        word[i] = *word_ptr;
        ++word_ptr;
        ++i;
    }
    word[i] = '\0';
}

DoublyLinkedList::DoublyLinkedList() {
    begin_->next = end_;
    end_->prev = begin_;
}

void DoublyLinkedList::push_back(const char* word_ptr) {
    BaseNode* node = begin_->next;

    while (node != end_) {
        Node* real_node = (Node*)node;

        if (strcmp(real_node->word, word_ptr) == 0) {
            ++real_node->count;
            return;
        }

        node = node->next;
    }

    Node* new_node = new Node(word_ptr);
    BaseNode* prev_end = end_->prev;

    new_node->prev = prev_end;
    new_node->next = end_;

    end_->prev = new_node;
    prev_end->next = new_node;

    ++size_;
}

void DoublyLinkedList::push_back(Node* node) {
    BaseNode* prev_end = end_->prev;

    node->prev = prev_end;
    node->next = end_;

    end_->prev = node;
    prev_end->next = node;

    ++size_;
}

void DoublyLinkedList::print(size_t node_count) const {
    BaseNode* node = begin_->next;

    while (node != end_ && node_count) {
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
    for (size_t i = 0; i < size_; ++i) {
        bool is_swapped = false;

        BaseNode* current_node = begin_->next;
        while (current_node != end_) {
            BaseNode* next_node = current_node->next;
            if (next_node == end_) {
                break;
            }

            Node* real_current_node = (Node*)current_node;
            Node* real_next_node = (Node*)next_node;

            if (real_current_node->count < real_next_node->count) {
                std::swap(real_current_node->word, real_next_node->word);
                std::swap(real_current_node->count, real_next_node->count);

                is_swapped = true;
            }

            current_node = next_node;
        }

        if (!is_swapped) {
            return;
        }
    }
}

DoublyLinkedList::~DoublyLinkedList() {
    BaseNode* node = begin_;
    while (node) {
        BaseNode* next_node = node->next;
        delete node;
        node = next_node;
    }
}
