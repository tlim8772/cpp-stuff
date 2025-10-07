#include <bits/stdc++.h>
using namespace std;

int x = 1000;

function<void()> f = [] () {
    static int x = 0;
    cout << x++ << endl;
};

function<void()> creator(int x) {
    return [x, ptr = shared_ptr<int>(new int(x))] () mutable { x++; cout << x << endl; };
}

int func(int x) {
    cout << 2 * x << endl;
    return x;
}

template <typename T>
function<T(T)> repeat(function<T(T)> f, int n) {
    if (n == 0) {
        return [] (T t) { return t; };
    } else {
        return [f, n] (T t) { x++; return f(repeat(f, n - 1)(t)); };
    }
    
}

void test1() {
    function<int(int)> f = [] (int x) { return x + 1; };
    function<int(int)> rep = repeat<int>(f, 10);
    cout << rep(0) << endl;
    cout << x << endl;
}

void test2() {
    auto f1 = f;
    f(); f1();
}

// when passing around lambda objects, the closure is copied or moved accordingly
// so variables inside the closure eg [x, p = shared_ptr<T>, u = unique_ptr<T>]
// they are copied or moved accordingly
void test3() {
    auto f = creator(10);
    f(); f();
    auto f2 = f;
    f2(); f2();
    f2 = std::move(f);
    f2(); f2();
}

int main() {
   test3();
}