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

class min_max {
    int m_min, m_max;
public:
    min_max() : m_min(-1), m_max(-1) {}

    void add(int price) {
        if (price > m_max) {
            if (m_min == -1) m_min = m_max;
            m_max = price;
        } else if (price < m_min || m_min == -1) {
            m_min = price;
        }
    }

    int diff() const {
        if (m_max == -1) {
            return -1;
        } else if (m_min == -1) {
            return 0;
        } else {
            return m_max - m_min;
        }
    }
};

struct Company {
    string name;
    min_max b92, b95, b98;
};

bool swap_p(Company *x, Company *y) {
    return x->name > y->name;
}

void sort(Company **A, int N) {
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (swap_p(A[j], A[j+1])) {
                swap(A[j], A[j+1]);
            }
        }
    }
}

void Solve() {
    Task("ExamTaskC56");

    int N;
    cin >> N;

    Company companies[20];
    int sz = 0;
    string company, street;
    int brand, price;
    for (int i = 0; i < N; i++) {
        cin >> brand >> price >> company >> street;

        bool found = false;
        for (int j = 0; !found && j < sz; j++) {
            if (companies[j].name == company) {
                switch (brand) {
                case 92: companies[j].b92.add(price); break;
                case 95: companies[j].b95.add(price); break;
                case 98: companies[j].b98.add(price); break;
                }
                found = true;
            }
        }
        if (!found) {
            companies[sz].name = std::move(company);
            switch (brand) {
            case 92: companies[sz].b92.add(price); break;
            case 95: companies[sz].b95.add(price); break;
            case 98: companies[sz].b98.add(price); break;
            }
            sz++;
        }
    }

    Company **ptr = new Company*[sz];
    for (int i = 0; i < sz; i++) {
        ptr[i] = &companies[i];
    }

    sort(ptr, sz);
    for (int i = 0; i < sz; i++) {
        cout
            << ptr[i]->name << " "
            << ptr[i]->b92.diff() << " "
            << ptr[i]->b95.diff() << " "
            << ptr[i]->b98.diff() << endl;
    }

    delete[] ptr;
}
