#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> s;
    s.insert({1, 1}); s.insert({2, 2}); s.insert({3, 3});
    auto it = s.find(2);
    auto it2 = it;
    it2--;

    cout << it->second << endl;
    cout << it2->second << endl;

    it2->second = 10;
    cout << (prev(it))->second << endl;
}