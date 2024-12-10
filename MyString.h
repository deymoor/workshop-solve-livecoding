#pragma once
#include <iostream>
#include <cstddef>

class MyString {
public:
    MyString() = default;
    MyString(const char* ptr);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);

    friend std::istream& operator>>(std::istream& input, MyString& str);
    friend std::ostream& operator<<(std::ostream& input, MyString& str);

    bool operator==(const MyString& other) const;
    void push_back(char ch);

    void clear();
    char* data();
    size_t size();

    ~MyString();
private:
    bool is_skip(char ch);

    char* _ptr = nullptr;
    size_t _cap = 0;
    size_t _sz = 0; 
};
