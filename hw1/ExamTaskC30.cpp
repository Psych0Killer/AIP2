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

struct Entry {
    int year;
    int student_n;
};

bool swap_p(Entry *x, Entry *y) {
    return
        x->student_n <  y->student_n ||
        x->student_n == y->student_n &&
        x->year > y->year;
}

void sort(Entry **A, int N) {
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (swap_p(A[j], A[j+1])) {
                swap(A[j], A[j+1]);
            }
        }
    }
}

void Solve() {
    Task("ExamTaskC30");

    Entry years[2010 - 1990 + 1];
    for (int i = 0; i < sz(years); i++) {
        years[i].year = 1990 + i;
        years[i].student_n = 0;
    }

    int N;
    cin >> N;
    string surname;
    int year_n = 0;
    for (int i = 0; i < N; i++) {
        int year, school_id;
        cin >> year >> school_id >> surname;
        if (years[year - 1990].student_n == 0) {
            year_n++;
        }
        years[year - 1990].student_n++;
    }

    Entry **ptr = new Entry*[sz(years)];
    for (int i = 0; i < sz(years); i++) {
        ptr[i] = &years[i];
    }
    sort(ptr, sz(years));

    double average = N / double(year_n);
    for (int i = 0; i < sz(years); i++) {
        if (ptr[i]->student_n >= average) {
            cout << ptr[i]->student_n << " " << ptr[i]->year << endl;
        }
    }
    delete[] ptr;
}
