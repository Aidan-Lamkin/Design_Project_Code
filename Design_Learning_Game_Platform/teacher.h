//
// Created by Aidan Lamkin on 6/15/21.
//

#ifndef GAME_TEACHER_H
#define GAME_TEACHER_H

#endif //GAME_TEACHER_H
#include <string>
#include <vector>
#include <map>
#include "book_set.h"
using namespace std;

class teacher{
public:
    teacher();
    teacher(string name, string school);
    string name;
    string school;
    void save_file();
    void read_file(string file_name);
    void add_book_set();
    vector<book_set> curriculum;
};