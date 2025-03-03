#include <bits/stdc++.h>
using namespace std;

string s = "hello";

optional<string> f() {
    return optional<string>(s);
}

int main() {
    optional<string> s2 = f();
    (*s2)[0] = 'g';
    cout << (*s2) << endl;
    cout << s << endl;
}