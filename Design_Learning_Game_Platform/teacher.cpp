//
// Created by Aidan Lamkin on 6/15/21.
//

#include "teacher.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

teacher::teacher() {
    name = "";
    school = "";
    curriculum.clear();
}

teacher::teacher(string n, string s) {
    name = n;
    school = s;
}
void teacher::add_book_set() {
    book_set current_book_set;
    curriculum.push_back(current_book_set);
}

void teacher::save_file() {
    string file_name = name + " teacher save.txt";
    ofstream save_file;
    save_file.open(file_name.c_str());

    if(!save_file.is_open()){
        cerr << "FILE DIDN'T OPEN" << endl;
        return;
    }

    save_file << name << endl;
    save_file << school << endl;

    for(int i = 0; i < curriculum.size(); i++){
        save_file << "BOOK:" << curriculum[i].title << endl;
        for(int j = 0; j < curriculum[i]._quizzes.size(); j++){
            save_file << "QUIZ:" << curriculum[i]._quizzes[j].ending_position << endl;
            for(int k = 0; k < curriculum[i]._quizzes[j]._questions.size(); k++){
                save_file << "QUESTION:" << curriculum[i]._quizzes[j]._questions[k].q << endl;
                for(int l = 0; l < curriculum[i]._quizzes[j]._questions[k].answers.size(); l++){
                    save_file << "ANSWER:" << curriculum[i]._quizzes[j]._questions[k].answers[l] << endl;
                }
                save_file << "CORRECT_ANSWER:" << curriculum[i]._quizzes[j]._questions[k]._correct_answer << endl;
            }
        }
    }

    save_file.close();
}

void teacher::read_file(string file_name){
    ifstream save_file;
    save_file.open(file_name.c_str());
    if(!save_file.is_open()){
        cerr << "FILE DIDN'T OPEN" << endl;
    }

    getline(save_file, name);
    getline(save_file, school);
    string line;
    vector<quiz> quizzes;
    while(!save_file.eof()) {
        if(curriculum.empty()) {
            getline(save_file, line);
        }
        if(line.substr(0,5) == "BOOK:") {
            string b_title = (line.substr(5, line.size() - 5));

            getline(save_file, line);
            while(line.substr(0, 5) == "QUIZ:") {
                int end = stoi(line.substr(5, line.size() - 5));


                vector<question> qs;
                string Q;
                vector<string> ans;
                string correct_ans;
                getline(save_file, line);

                while(line.substr(0, 9) == "QUESTION:" || line.substr(0,7) == "ANSWER:" || line.substr(0, 15) == "CORRECT_ANSWER:") {
                    if (line.substr(0, 9) == "QUESTION:") {
                        Q = line.substr(9, line.size() - 9);
                    }
                    else if (line.substr(0, 7) == "ANSWER:") {
                        ans.push_back(line.substr(7, line.size() - 7));
                    }
                    else if (line.substr(0, 15) == "CORRECT_ANSWER:") {
                        correct_ans = line.substr(15, line.size() - 15);
                        question current_question = question(Q, ans, correct_ans);
                        qs.push_back(current_question);
                        ans.clear();
                    }
                    getline(save_file, line);
                }
                quizzes.push_back(quiz(end, qs));
            }
            curriculum.push_back(book_set(b_title, quizzes));
            quizzes.clear();
        }
    }

    save_file.close();
    return;
}