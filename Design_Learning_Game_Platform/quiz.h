//
// Created by Aidan Lamkin on 6/15/21.
//

#ifndef GAME_QUIZ_H
#define GAME_QUIZ_H

#endif //GAME_QUIZ_H
#include <string>
#include <vector>
#include <map>
#include "question.h"
using namespace std;

class quiz{
public:
    quiz();
    quiz(int end, vector<question>qs);
    int ending_position;
    vector<question> _questions;
};