#include <bits/stdc++.h>
using namespace std;

struct A {
    int a;

    A(int a): a(a) {}

    A(const A& other): a(other.a) {
        cout << "copied" << endl;
    }

    A(A&& other): a(other.a) {
        cout << "moved" << endl;
    }
};

struct B {
    A a;

    B(int b): a(2 * b) {}
};

A f(B* bptr) {
    return bptr->a;
};

A f2() {
   
    return A(5);
}

int main() {
    //A a(10);
    //A a2 = a;
    
    B b1(10);
    A a3 = f(&b1);

    A a4 = f2();
}

