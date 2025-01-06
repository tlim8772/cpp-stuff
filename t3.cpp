#include <bits/stdc++.h>
using namespace std;

// base class must be defined first, as this is overloading, not specialisation
template <typename T>
T getIth(int idx, T t) {
    return t;
}



// cannot have different types in the variadic arguments, as the return type T is fixed from the 1st type
template <typename T, typename... Args>
T getIth(int idx, T t, Args... args) {
    if (idx == 0) return t;
    return getIth(idx - 1, args...);
}






int main() {
    cout << getIth(2, 'c', 'd', 'e') << endl;
}

