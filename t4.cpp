#include <bits/stdc++.h>
using namespace std;

template <int n>
struct Fact {
    static constexpr int res = n * Fact<n - 1>::res;
};

// this time got to define the specialised type after class definition
template <>
struct Fact<0> {
    static constexpr int res = 1;
};

template <int n>
struct Fib {
    static constexpr int res = Fib<n - 1>::res + Fib<n - 2>::res;
};

template <>
struct Fib<0> {
    static constexpr int res = 0;
};

template <>
struct Fib<1> {
    static constexpr int res = 1;
};

int main() {
    cout << Fact<10>::res << endl;
    cout << Fib<10>::res << endl;
}
