//
// Created by Aidan Lamkin on 6/15/21.
//
#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

#ifndef GAME_STUDENT_H
#define GAME_STUDENT_H

#endif //GAME_STUDENT_H

class student {
public:
    student(string code);
    student();
    string get_code();
    string get_name();
    string get_school();
    set<string> get_teachers();
    int get_level();
    int get_experience();
    void save(string file_name);
    void read(string file_name);
    void load_stats();
    void quiz_experience(int correct_answers);
private:
    string _code;
    string _name;
    set<string> _teachers;
    string _school;
    int _experience;
};