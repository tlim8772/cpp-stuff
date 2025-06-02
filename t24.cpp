#include <bits/stdc++.h>
using namespace std;

template <typename T>
void decorator(T f) {
    cout << "calling func" << endl;
    cout << f() << endl;;
}

int main() {
    function<int()> f = [] () {return 10;};
    decorator(f);
}