//
// Created by Aidan Lamkin on 6/15/21.
//

#include "question.h"
#include <iostream>
using namespace std;

question::question(){
    cin.ignore();
    cout << "Enter in the question: " << endl;
    getline(cin, q);

    cout << "Enter all possible answers. Press enter after each one and type 'END' to stop." << endl;
    string input;
    while(input != "END"){
        getline(cin, input);
        if(input != "END"){
            answers.push_back(input);
        }
    }

    cout << "Which numbered answer was the correct answer?" << endl;
    cin >> input;

    _correct_answer = answers[stoi(input) - 1];
}

question::question(string Q, vector<string> ans, string c_a) {
    q = Q;
    answers = ans;
    _correct_answer = c_a;
}