//
// Created by Aidan Lamkin on 6/15/21.
//

#include "book_set.h"
#include <iostream>
#include <string>
using namespace std;

book_set::book_set() {
    string input;
    cin.ignore();
    cout << "What is the title of the book?" << endl;
    getline(cin, input);
    title = input;

    int number;
    cout << "How many quizzes are in " << title << "?" << endl;
    cin >> number;
    for(int i = 0; i < number; i++){
        quiz current_quiz;
        _quizzes.push_back(current_quiz);
    }
}

book_set::book_set(string name, vector<quiz> quiz) {
    title = name;
    _quizzes = quiz;
}