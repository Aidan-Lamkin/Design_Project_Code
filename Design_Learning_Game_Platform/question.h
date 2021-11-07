//
// Created by Aidan Lamkin on 6/15/21.
//

#ifndef GAME_QUESTION_H
#define GAME_QUESTION_H

#endif //GAME_QUESTION_H
#include <string>
#include <vector>
using namespace std;

class question{
public:
    question();
    question(string Q, vector<string> ans, string c_a);
    string q;
    vector<string> answers;
    string _correct_answer;
};