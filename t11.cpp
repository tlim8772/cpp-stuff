#include <bits/stdc++.h>
using namespace std;

template <int X>
int factorial() {
    int a = X;
    int b;
    return X * factorial<X - 1>();
}

template <>
int factorial<0>() {
    return 1;
}

int main() {
    cout << factorial<10>() << endl;
}