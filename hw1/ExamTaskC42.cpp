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

struct Resident {
    double dept;
    string surname;
    int room_n;
};

bool swap_p(Resident *x, Resident *y) {
    return x->dept < y->dept;
}

void sort(Resident **A, int N) {
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (swap_p(A[j], A[j+1])) {
                swap(A[j], A[j+1]);
            }
        }
    }
}

void Solve() {
    Task("ExamTaskC42");

    auto porch_n = [](int room_n) {
        return (room_n - 1) / 36 + 1;
    };

    Resident porches[4];
    for (int i = 0; i < sz(porches); i++) {
        porches[i].dept = 0.0;
        porches[i].room_n = 0;
    }

    int N;
    cin >> N;
    Resident man;
    for (int i = 0; i < N; i++) {
        cin >> man.dept >> man.surname >> man.room_n;

        if (porches[porch_n(man.room_n)-1].dept < man.dept) {
            porches[porch_n(man.room_n)-1] = std::move(man);
        }
    }

    Resident **ptr = new Resident*[sz(porches)];
    for (int i = 0; i < sz(porches); i++) {
        ptr[i] = &porches[i];
    }
    sort(ptr, sz(porches));

    for (int i = 0; i < sz(porches); i++) {
        if (ptr[i]->dept != 0.0) {
            cout
                << fixed
                << setprecision(2)
                << ptr[i]->dept
                << " "
                << porch_n(ptr[i]->room_n)
                << " "
                << ptr[i]->room_n
                << " "
                << ptr[i]->surname
                << endl;
        }
    }
}
