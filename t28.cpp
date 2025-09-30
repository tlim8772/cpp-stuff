#include <bits/stdc++.h>
using namespace std;

struct A {
    int a = 0;
    int *ptr = new int(10);

    A(int a): a(a) {
        cout << "ctor A" << a << endl;
    }

    ~A() {
        delete ptr;
        cout << "dtor A" << a << endl;
    }
}; 

void f() {
    A a(10);
    throw runtime_error("Ooops");
}

int main() {
    f();
}