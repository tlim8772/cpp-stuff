#include <bits/stdc++.h>
using namespace std;

auto f = [] () {
    static int x = 0;
    x++;
    cout << x << endl;
};

int main() {
    function<void()> f1 = f;
    function<void()> f2 = f;

    f1();
    f2();
}