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
    int school_n;
    int total_score;
};

void Solve() {
    Task("ExamTaskC61");

    int N;
    cin >> N;
    Student *students = new Student[N];
// T(2N). Thus, O(N)
    int min = -1;
    for (int i = 0; i < N; i++) {
        int school_n, x, y, z;

        cin >> students[i].surname
            >> students[i].initials
            >> students[i].school_n
            >> x >> y >> z;
        int total = x + y + z;
        students[i].total_score = total;
        if (total < min || min == -1) {
            min = total;
        }
    }

    cout << min << endl;
    for (int i = 0; i < N; i++) {
        if (students[i].total_score == min) {
            cout << students[i].surname
                 << " "
                 << students[i].initials
                 << " "
                 << students[i].school_n
                 << endl;
        }
    }

    delete[] students;
}
