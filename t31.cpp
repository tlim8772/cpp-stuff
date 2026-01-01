#include <bits/stdc++.h>
using namespace std;

struct A {
    int& cnt;
    A(int& cnt): cnt(cnt) {}

    A(const A& other): cnt(other.cnt) {}

    void run() {
        cout << cnt++ << endl;
    }
};

int main() {
    int x = 10;
    A a(x);
    a.run();

    A b = a;
    b.run();

    A c = std::move(a);
    c.run();
    b.run();
}