#include <bits/stdc++.h>
using namespace std;
using stdmo = std::memory_order;


atomic<int> x{0};

int main() {
    x.fetch_add(1, stdmo::relaxed);
    cout << x.load(stdmo::relaxed) << endl;
}