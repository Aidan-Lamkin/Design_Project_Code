cmake_minimum_required(VERSION 3.19)
project(Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Game main.cpp student.cpp student.h teacher.cpp teacher.h quiz.cpp quiz.h question.cpp question.h book_set.cpp book_set.h)