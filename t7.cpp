#include <bits/stdc++.h>
using namespace std;

class T {
public:
    int x;

    T(int x): x(x) {
        //cout << "Default" << endl;
    }

    T(const T& t) {
        cout << "Copied" << endl;
        x = t.x;
    }

    T(T&& t) {
        cout << "Moved" << endl;
        x = t.x;
    };
};

T globalT = T(1001);

T f() {
    T t(69);
    return t;
}

T f2() {
    return T(70);
}

T f3() {
    return globalT;
}


int main() {
    T t = T(100);

    //T t2 = t;

    //T t3 = f();

    //T t4 = f2();

    T t5 = f3();
}