#include <bits/stdc++.h>
using namespace std;

struct A {
    int f(string s) {
        return s.size();
    }

    int f2(string s) {
        return 2 * s.size();
    }
};

int main() {
    vector<int (A::*)(string)> arr;
    arr.insert(arr.end(), {&A::f, &A::f2});
    A a;
    for (auto f : arr) {
        cout << (a.*f)("hello") << endl;
    }

    vector<int (*)(int)> arr2;

}