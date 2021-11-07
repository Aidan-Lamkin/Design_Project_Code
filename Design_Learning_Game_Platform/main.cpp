#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "student.h"
#include "teacher.h"
#include <iomanip>
#include "stdlib.h"
using namespace std;


int main() {
    student user;
    teacher teach;
    string input;
    char num_select;
    while (input != "Student" && input != "student" && input != "Teacher" && input != "teacher") {
        cout << "Who's logging in? Student or Teacher?" << endl;
        cin >> input;
    }

    if(input == "Student" || input == "student"){
        string input2;
        while(input2 != "L" && input2 != "l" && input2 != "S" && input2 != "s") {
            cout << "Are you logging in or signing up? (Type L or S)" << endl;
            cin >> input2;
        }

        if(input2 == "S" || input2 == "s"){
            string code;
            cout << "Enter the code found on your bookmark?" << endl;
            cin >> code;
            user = student(code);
        }

        else{
            string save_file;
            cout << "Type in your name:" << endl;
            cin.ignore();
            getline(cin, save_file);
            save_file += " game save.txt";
            user.read(save_file);
        }

        while(input != "quit" && input != "Quit") {
            cout << "Do you want to play a level, or access your stats? (Type play or stats)" << endl;
            while (input != "play" && input != "Play" && input != "Stats" && input != "stats") {
                cin >> input;
            }

            if (input == "Play" || input == "play") {
                cout << "Which teacher's levels do you want to play? (Select number)" << endl;

                vector<string> ts;
                for(string t: user.get_teachers()){
                    ts.push_back(t);
                }
                sort(ts.begin(), ts.end());

                for(int i = 0; i < ts.size(); i++){
                    cout << setw(12) << left << i + 1  << right << ts[i] << endl;
                }

                num_select = 'B';
                cin.ignore();
                while(!isdigit(num_select) || int(num_select) - 48 <= 0 || int(num_select) - 48 > ts.size()) {
                    cin >> num_select;
                }

                int index = int(num_select) - 49;
                string current_teacher = ts[index];
                string teacher_file_name = current_teacher + " teacher save.txt";

                teach.read_file(teacher_file_name);

                cout << "Which book do you want to practice? (Select number)" << endl;
                for(int i = 0; i < teach.curriculum.size(); i++){
                    cout << setw(12) << left << i + 1 << right << teach.curriculum[i].title << endl;
                }

                num_select = 'B';
                while(!isdigit(num_select) || int(num_select) - 48 <= 0 || int(num_select) - 48 > teach.curriculum.size()) {
                    cin >> num_select;
                }

                book_set current_book_set = teach.curriculum[int(num_select) - 49];

                cout << "What level do you want to play? (Select number)" << endl;
                cout << setw(12) << left << "Level #" << setw(30) << right << "Up to Page #" << endl;

                for(int i = 0; i < current_book_set._quizzes.size(); i++){
                    cout << setw(12) << left << i + 1  << setw(30) << right << current_book_set._quizzes[i].ending_position << endl;
                }

                num_select = 'B';
                while(!isdigit(num_select) || int(num_select) - 48 <= 0 || int(num_select) - 48 > current_book_set._quizzes.size()) {
                    cin >> num_select;
                }

                quiz current_quiz = current_book_set._quizzes[int(num_select) - 49];

                int correct_counter = 0;
                cout << "Type the number for the correct answer." << endl << endl;
                for(int i = 0; i < current_quiz._questions.size(); i++){
                    cout << current_quiz._questions[i].q << endl << endl;
                    for(int j = 0; j < current_quiz._questions[i].answers.size(); j++){
                        cout << setw(6) << left << j + 1 << right << setw(40) << current_quiz._questions[i].answers[j] << endl;
                    }
                    num_select = 'B';
                    cin.ignore();
                    while(!isdigit(num_select) || int(num_select) - 48 <= 0 || int(num_select) - 48 > current_quiz._questions[i].answers.size()) {
                        cin >> num_select;
                    }
                    if(current_quiz._questions[i].answers[int(num_select - 49)] == current_quiz._questions[i]._correct_answer){
                        correct_counter++;
                    }
                }

                cout << endl << "You got " << correct_counter << " out of " << current_quiz._questions.size() << " correct!" << endl;
                user.quiz_experience(correct_counter);
                cout << "You gained " << correct_counter * 20 << " experience points!" << endl << endl;
            }
            else {
                user.load_stats();
            }

            cout << "Type 'Quit' if you would like to exit the game, if not type 'Go' enter." << endl;
            while(input != "Quit" && input != "quit" && input != "Go" && input != "go") {
                cin >> input;
            }
            teach = teacher();
        }

        string file_name;
        ofstream save_file;

        while(!save_file.is_open()) {
            file_name = user.get_name() + " game save.txt";
            save_file.open(file_name.c_str());
            if (!save_file.is_open()) {
                cerr << "FILE DIDN'T OPEN" << endl;
            }
        }

        save_file << user.get_code() << endl;
        save_file << user.get_name() << endl;
        for(string teacher: user.get_teachers()){
            save_file << teacher << ',';
        }

        save_file << endl;
        save_file << user.get_school() << endl;
        save_file << user.get_experience() << endl;
        save_file.close();
    }
    else{

        string input2;
        while(input2 != "L" && input2 != "l" && input2 != "S" && input2 != "s") {
            cout << "Are you logging in or signing up? (Type L or S)" << endl;
            cin >> input2;
        }

        if(input2 == "l" || input2 == "L"){
            cin.ignore();
            string save_file;
            cout << "Type in your name:" << endl;
            getline(cin, save_file);
            save_file += " teacher save.txt";
            teach.read_file(save_file);
        }

        else{
            cin.ignore();
            string name;
            string school;
            cout << "What is your name?" << endl;
            getline(cin, name);
            cout << "What school are you employed under?" << endl;
            getline(cin, school);
            teach = teacher(name, school);
        }


        while(input != "N" && input != "n") {
            input = "temp";
            cout << "Would you like to add to the curriculum? (Y/N)" << endl;

            while (input != "Y" && input != "y" && input != "N" && input != "n") {
                cin >> input;
            }
            if (input == "Y" || input == "y") {
                teach.add_book_set();
            }
        }
        teach.save_file();
    }
    return 0;
}
