#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int to_base(int k, int n) {
    int val = 0;
    int exp = 1;
    while (k) {
        val += k % n * exp;
        k /= n;
        exp *= 10;
    }

    return val;
}

int main() {
    fstream f("random.txt", ios::in|ios::out|ios::binary);

    /* Print all numbers */
    while (f.peek() != EOF) {
        int x;
        f.read((char *)&x, sizeof(x));
        cout << x << " ";
    }
    cout << endl;


    int p, k;
    char ans = 'y';
    while (ans != 'n' && ans != 'N') {
        cout << "Please, enter array index and base: ";
        cin >> k >> p;
        int x;
        f.seekg((k - 1) * sizeof(int));
        f.read((char *)&x, sizeof(x));
        x = to_base(x, p);
        f.seekp((k - 1) * sizeof(int));
        f.write((char *)&x, sizeof(x));

        cout << x << endl;
        cout << "Do you want to continue? Y/N" << endl;
        cin >> ans;
    }


    return 0;
}
