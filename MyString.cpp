#include "MyString.h"

MyString::MyString(const char* ptr) {
    if (!ptr) {
        return;
    }

    while (*ptr != '\0') {
        push_back(*ptr);
        ++ptr;
    }
}

MyString::MyString(const MyString& other): capacity_(other.capacity_), size_(other.size_) {
    data_ = new char[capacity_];
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

MyString& MyString::operator=(const MyString& other) {
    clear();

    capacity_ = other.capacity_;
    size_ = other.size_;

    data_ = new char[capacity_];
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }

    return *this;
}

bool MyString::is_skip(char ch) {
    return ch == ' ' || ch == '\n';
}

std::istream& operator>>(std::istream& input, MyString& str) {
    str.clear();

    while (input && str.is_skip(input.peek())) {
        input.get();
    }

    while (input && !str.is_skip(input.peek())) {
        str.push_back(input.get());
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, MyString& str) {
    output.write(str.data_, str.size_);

    return output;
}

void MyString::push_back(char ch) {
    if (size_ == capacity_) {
        char* new_ptr = new char[capacity_ * 2 + 1];
        for (size_t i = 0; i < size_; ++i) {
            new_ptr[i] = data_[i];
        }
        capacity_ = capacity_ * 2 + 1;

        delete[] data_;
        data_ = new_ptr;
    }
    data_[size_] = ch;
    ++size_;
}

bool MyString::operator==(const MyString& other) const {
    if (capacity_ != other.capacity_ || size_ != other.size_) {
        return false;
    }

    for (size_t i = 0; i < size_; ++i) {
        if (data_[i] != other.data_[i]) {
            return false;
        }
    }

    return true;
}

void MyString::clear() {
    delete[] data_;

    data_ = nullptr;
    capacity_ = 0;
    size_ = 0;
}

char* MyString::data() {
    return data_;
}

size_t MyString::size() {
    return size_;
}

MyString::~MyString() {
    delete[] data_;
}
