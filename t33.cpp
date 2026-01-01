#include <bits/stdc++.h>
using namespace std;

struct T {
    int f1(int x) {
        return x + 1;
    }

    int f2(int x) {
        return x + 2;
    }
};

int f3(int x, int y) {
    return x + y;
}

int main() {
    T t;
    vector<function<int(int)>> funcs = {
        [&t] (int x) {return t.f1(x);},
        [&t] (int x) {return t.f2(x);}
    };

    using Temp = int (T::*) (int);
    vector<Temp> funcs2 = {
        &T::f1,
        &T::f2
    };

    int y = 10;
    for (auto& f : funcs) {
        cout << f(y) << endl;
    }

    y = 100;
    for (auto& f : funcs2) {
        cout << (t.*f)(y) << endl;
    }

    int (*fptr) (int,int) = f3;
    cout << f3(200, 300) << endl;
};