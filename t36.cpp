#include <iostream>
using namespace std;

void f() {
    if (int x = 1; x > 5) {
        cout << x << endl;
    }
}

int main() {
    f();
}