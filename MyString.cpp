#include "MyString.h"

MyString::MyString(const char* ptr) {
    while (*ptr != '\0') {
        push_back(*ptr);
        ++ptr;
    }
}

MyString::MyString(const MyString& other): _cap(other._cap), _sz(other._sz) {
    _ptr = new char[_cap];
    for (size_t i = 0; i < _sz; ++i) {
        _ptr[i] = other._ptr[i];
    }
}

MyString& MyString::operator=(const MyString& other) {
    clear();

    _cap = other._cap;
    _sz = other._sz;

    _ptr = new char[_cap];
    for (size_t i = 0; i < _sz; ++i) {
        _ptr[i] = other._ptr[i];
    }

    return *this;
}

bool is_skip(char ch) {
    return ch == ' ' || ch == '\n';
}

std::istream& operator>>(std::istream& input, MyString& str) {
    str.clear();

    while (input && is_skip(input.peek())) {
        input.get();
    }

    while (input && !is_skip(input.peek())) {
        str.push_back(input.get());
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, MyString& str) {
    output.write(str._ptr, str._sz);

    return output;
}

void MyString::push_back(char ch) {
    if (_sz == _cap) {
        char* new_ptr = new char[_cap * 2 + 1];
        for (size_t i = 0; i < _sz; ++i) {
            new_ptr[i] = _ptr[i];
        }
        _cap = _cap * 2 + 1;

        delete[] _ptr;
        _ptr = new_ptr;
    }
    _ptr[_sz] = ch;
    ++_sz;
}

bool MyString::operator==(const MyString& other) const {
    if (_cap != other._cap || _sz != other._sz) {
        return false;
    }

    for (size_t i = 0; i < _sz; ++i) {
        if (_ptr[i] != other._ptr[i]) {
            return false;
        }
    }

    return true;
}

void MyString::clear() {
    delete[] _ptr;

    _ptr = nullptr;
    _cap = 0;
    _sz = 0;
}

char* MyString::data() {
    return _ptr;
}

size_t MyString::size() {
    return _sz;
}

MyString::~MyString() {
    delete[] _ptr;
}
