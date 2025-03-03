#include "A.h"
#include "B.h"
#include <iostream>
using namespace std;

void A::f(const B& b) {
    cout << b.b << endl;
}

void B::f(const A& a) {
    cout << a.a << endl;
}

int main() {
    A a{10};
    B b{69};

    a.f(b);
    b.f(a);
}