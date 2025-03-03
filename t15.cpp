#include <iostream>
using namespace std;

struct A {
    int a;

    virtual void f() {
        cout << "i am A" << endl;
    }
};

struct B: public A {
    int b;

    void f() {
        cout << "I am B" << endl;
    }
};

struct C: public B {
    int c;

    void f() {
        cout << "I am C" << endl;
    }
};

int main() {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(A&) << endl;

    B b;
    A& a = b;
    a.f();
    
    C c;
    B& a2 = c;
    a2.f();
    
}