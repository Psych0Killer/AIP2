#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define UPPERBOUND 100

int main() {
    int N;
    fstream f("random.txt", ios::out|ios::binary);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x = rand() % UPPERBOUND;
        f.write((char *)&x, sizeof(x));
    }

    return 0;
}
