//
// Created by Aidan Lamkin on 6/15/21.
//

#ifndef GAME_BOOK_SET_H
#define GAME_BOOK_SET_H

#endif //GAME_BOOK_SET_H

#include <string>
#include <iostream>
#include "quiz.h"
using namespace std;

class book_set{
public:
    book_set();
    book_set(string name, vector<quiz> quizs);
    string title;
    vector<quiz> _quizzes;
};