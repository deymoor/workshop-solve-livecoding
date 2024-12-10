cmake_minimum_required(VERSION 3.12)

project(
        livecoding
        VERSION 1.0
        DESCRIPTION "Solve livecoding"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Werror -Wextra -pedantic-errors -fsanitize=address)
add_link_options(-fsanitize=address)

add_executable(${PROJECT_NAME}
        main.cpp
        MyString.cpp
        parser.cpp
        DoublyLinkedList.cpp)
