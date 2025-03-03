#include <iostream>
using namespace std;

struct A {
    int a;

   

    void show() {
        cout << a << endl;
    }
};

struct B: public A {
    B(int b) {
        A::a = b;
    }

    void display() {
        A::show();
    }
};

int main() {
    B b(10);
    b.display();

    B b2(11);
    b2.display();
}