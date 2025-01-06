#include <bits/stdc++.h>
using namespace std;


// base function is an overload, so must be defined first
template <typename T>
T sum(T t) {
    return t;
}

template <typename T, typename... Args>
T sum(T t, Args... args) {
    t += sum(args...);
    return t;
}

int main() {
    cout << sum(string("a"), string("b"), string("c")) << endl;
    cout << sum<float>(1, 2.0, 3.5) << endl;
}