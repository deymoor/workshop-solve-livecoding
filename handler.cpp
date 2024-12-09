#include <fstream>
#include <iostream>
#include <sstream>

#include "handler.h"
#include "parser.h"

class LinkedList {
public:
    LinkedList() {
        begin->next = end;
        end->prev = begin;
    }

    struct BaseNode {
        BaseNode* prev = nullptr;
        BaseNode* next = nullptr;
    };

    struct Node : BaseNode {
        MyString word;
        size_t count = 1;

        Node(MyString& word): word(word) {}
    };

    void push_back(MyString& word) {
        BaseNode* node = begin->next;

        while (node != end) {
            Node* real_node = (Node*)node;

            if (real_node->word == word) {
                ++real_node->count;
                return;
            }

            node = node->next;
        }

        Node* new_node = new Node(word);
        BaseNode* prev_end = end->prev;

        new_node->prev = prev_end;
        new_node->next = end;

        end->prev = new_node;
        prev_end->next = new_node;

        ++_sz;
    }

    void print(size_t top_count) const {
        BaseNode* node = begin->next;

        while (node != end && top_count) {
            Node* real_node = (Node*)node;
            std::cout << real_node->word << ' ' << real_node->count << std::endl;

            node = node->next;
            --top_count;
        }
    }

    void sort() {
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

    ~LinkedList() {
        BaseNode* node = begin;
        while (node) {
            BaseNode* next_node = node->next;
            delete node;
            node = next_node;
        }
    }
private:
    BaseNode* begin = new BaseNode();
    BaseNode* end = new BaseNode();

    size_t _sz = 0;
};

bool handle(const Arguments& args) {
    std::ifstream file(args.path);

    if (!file) {
        std::cerr << "File doesn't exist" << std::endl;
        return true;
    }

    LinkedList list;
    MyString word;
    while (file >> word) {
        list.push_back(word);
    }

    list.sort();
    list.print(args.top_count);

    return false;
}
