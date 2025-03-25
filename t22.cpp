#include <bits/stdc++.h>
using namespace std;

struct T {
    int num;

    static int h(int x) {
        return 3 * x;
    }

    int f(int x) {
        return 2 * x;
    }
};

void call(function<int(int)> f) {
    cout << f(11) << endl;
}


int main() {
    int (T::*func)(int) = &T::f;
    int T::*x = &T::num;

    T t;
    t.num = 99;
    cout << (t.*func)(10) << endl;
    cout << t.*x << endl;

    int (*func2)(int) = &T::h;
    cout << func2(10) << endl;
}