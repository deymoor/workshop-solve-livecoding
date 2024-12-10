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

    char* data_ = nullptr;
    size_t capacity_ = 0;
    size_t size_ = 0; 
};
