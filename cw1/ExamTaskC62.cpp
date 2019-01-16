#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <utility>
#pragma hdrstop
#include "pt4exam.h"
using namespace std;

#define sz(A) (sizeof(A) / sizeof(*A))

struct Student {
    string surname;
    string initials;
    int total_score;
};

void Solve() {
    Task("ExamTaskC62");

    int N;
    cin >> N;
    Student *students = new Student[N];

    int max_score1 = -1, max_score2 = -1;
    for (int i = 0; i < N; i++) {
        int school_n, x, y, z;

        cin >> students[i].surname
            >> students[i].initials
            >> x >> y >> z
            >> school_n;

        int ms = x + y + z;
        students[i].total_score = ms;
        if (ms == max_score1) {
            // pass
        } else if (ms > max_score1) {
            max_score2 = max_score1;
            max_score1 = ms;
        } else if (ms > max_score2) {
            max_score2 = ms;
        }
    }

    cout << max_score1 << " " << max_score2 << endl;
    for (int i = 0; i < N; i++) {
        if (students[i].total_score == max_score1 ||
            students[i].total_score == max_score2) {
            cout << students[i].surname
                 << " "
                 << students[i].initials
                 << " "
                 << students[i].total_score
                 << endl;
        }
    }

    delete[] students;
}
