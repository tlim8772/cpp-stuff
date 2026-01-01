#include <bits/stdc++.h>
using namespace std;

struct A {
    int x = -1;
};

struct B {
    bool b1, b2, b3, b4;
    int i1, i2, i3;
};

int main() {
    set<int> s;
    cout << sizeof(set<int>::iterator) << endl;

    atomic<A> a;
    cout << a.load().x << endl;

    cout << sizeof(B) << endl;
}