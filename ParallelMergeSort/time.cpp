#include <bits/stdc++.h>
#include <chrono>
using namespace std;

struct Clock {
    chrono::time_point<chrono::high_resolution_clock> s, e;

    void start() {
        s = chrono::high_resolution_clock::now();
    }

    void end() {
        e = chrono::system_clock::now();
    }

    double time() {
        return chrono::duration_cast<chrono::nanoseconds>(e - s).count() / 1e9;
    }
};