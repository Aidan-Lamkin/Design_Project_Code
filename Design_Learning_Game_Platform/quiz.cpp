//
// Created by Aidan Lamkin on 6/15/21.
//

#include "quiz.h"
#include <string>
#include <iostream>
using namespace std;
quiz::quiz() {
    int input;
    cout << "What page number does this quiz end on?" << endl;
    cin >> input;
    ending_position = input;

    cout << "How many questions are on this quiz?" << endl;
    cin >> input;

    for(int i = 0; i < input; i++){
        question current_question;
        _questions.push_back(current_question);
    }
}

quiz::quiz(int end, vector<question> qs) {
    ending_position = end;
    _questions = qs;
}