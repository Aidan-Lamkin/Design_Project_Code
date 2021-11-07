//
// Created by Aidan Lamkin on 6/15/21.
//
#include <cmath>
#include "student.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

student::student(string code) {
    _code = code;

    cin.ignore();
    cout << "Enter your name:" << endl;
    getline(cin, _name);

    string teacher;
    cout << "Enter in your teachers names. When you are done enter 'END'. Press enter after each entry." << endl;
    while(teacher != "END"){
        getline(cin, teacher);
        if(teacher != "END") {
            _teachers.insert(teacher);
        }
    }

    cout << "Enter your school's name." << endl;
    getline(cin, _school);

    _experience = 0;
}

student::student(){
    _code = "";
    _name = "";
    _school = "";
}

string student::get_code() {
    return _code;
}

string student::get_name() {
    return _name;
}

string student::get_school() {
    return _school;
}

int student::get_level() {
    int level = pow(_experience / 2, .33);
    if(level == 0){
        return 1;
    }
    else{
        return level;
    }
}
set<string> student::get_teachers(){
    return _teachers;
}
int student::get_experience() {
    return _experience;
}

void student::read(string file_name) {
    ifstream save_file;
    save_file.open(file_name.c_str());
    getline(save_file, _code);
    getline(save_file, _name);
    string list;
    getline(save_file, list);
    string temp = "";
    for(int i = 0; i < list.size(); i++){
        if(list[i] != ','){
            temp += list[i];
        }
        else{
            _teachers.insert(temp);
            temp = "";
        }
    }
    getline(save_file, _school);
    string xp;
    getline(save_file, xp);
    _experience = stoi(xp);
    save_file.close();

    return;
}

void student::load_stats() {
    for(int i = 0; i < 5; i++){
        if(i == 0){
            cout << setw(12) << left << "Name:" << setw(30) << right << get_name() << endl;
        }
        else if(i == 1){
            cout << setw(12) << left << "Code:" << setw(30) << right << get_code() << endl;
        }
        else if(i == 2){
            cout << setw(12) << left << "School:" << setw(30) << right << get_school() << endl;
        }
        else if (i == 3){
            vector<string> teach;
            for(string t: get_teachers()){
                teach.push_back(t);
            }
            sort(teach.begin(), teach.end());
            cout << setw(12) << left << "Teacher(s):" << setw(30) << right << teach[0] << endl;
            for(int j = 1; j < teach.size(); j++){
                cout << setw(12) << "            " << left << setw(30) << right << teach[j] << endl;
            }
        }
        else{
            cout << setw(12) << left << "Level:" << setw(30) << right << get_level() << endl;
        }
    }

}

void student::quiz_experience(int correct_answers) {
    _experience += correct_answers * 20;
}