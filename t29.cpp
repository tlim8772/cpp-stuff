#include <bits/stdc++.h>
#include <thread>
using namespace std;

int f(int x) {
    this_thread::sleep_for(100ms);
    return x;
}

int main() {
    future<int> fut = async(f, 100);
    cout << fut.get() << endl;
}