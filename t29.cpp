#include <bits/stdc++.h>
#include <thread>
using namespace std;

int y = 19;

int& f(int x) {
    this_thread::sleep_for(100ms);
    return y;
}

int main() {
    future<int&> fut = async(f, 100);
    int& z = fut.get();
    z = 79;
    cout << y << endl;
}