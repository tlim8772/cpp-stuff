#include <bits/stdc++.h>
using namespace std;

void f(mutex& mut, int& c) {
    lock_guard lock(mut);
    c += 1;
}

int main() {
    mutex mut;
    int c = 0;
    thread t1 = thread{f, ref(mut), ref(c)};
    thread t2 = thread{f, ref(mut), ref(c)};
    t2.join();
    t1.join();
    cout << c << endl;
}