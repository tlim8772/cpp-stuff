#include <bits/stdc++.h>
using namespace std;

void f(int& n) {
    cout << "I take refs" << endl;
}

int main() {
    int x = 10;
    int& y = x;
    thread t1(f, y);
    t1.join();
}