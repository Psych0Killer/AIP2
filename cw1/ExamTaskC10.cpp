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

struct Client {
    int months;
    int id;
};

bool swap_p(Client *x, Client *y) {
    return
        x->months >  y->months ||
        x->months == y->months &&
        x->id > y->id;
}

void sort(Client **A, int N) {
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (swap_p(A[j], A[j+1])) {
                swap(A[j], A[j+1]);
            }
        }
    }
}

#define MAX_ID 90

void Solve() {
    Task("ExamTaskC10");

    auto from_id = [](int id) {
        return id - 10;
    };
    auto to_id = [](int id) {
        return id + 10;
    };

    Client clients[MAX_ID];
    for (int i = 0; i < MAX_ID; i++) {
        clients[i].id = to_id(i);
        clients[i].months = 0;
    }

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int id, hours, year, month;
        cin >> id >> hours >> year >> month;

        clients[from_id(id)].months++;
    }

    Client **ptr = new Client*[sz(clients)];
    for (int i = 0; i < sz(clients); i++) {
        ptr[i] = &clients[i];
    }
    sort(ptr, sz(clients));

    for (int i = 0; i < sz(clients); i++) {
        if (ptr[i]->months > 0) {
            cout << ptr[i]->months << " " << ptr[i]->id << endl;
        }
    }
    delete[] ptr;
}
