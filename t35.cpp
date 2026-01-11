#include <bits/stdc++.h>
using namespace std;

template <typename T>
T sum(T t) {
    return t;
}

template <typename T, typename... Ts>
T sum(T t, Ts... args) {
    return t + sum(args...);
}

int main() {
    cout << sum(1, 2, 3) << endl;
}