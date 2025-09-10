#include <bits/stdc++.h>
using namespace std;

vector<thread> ts;
mutex mut;
void f(int x) {
    unique_lock<mutex> lock(mut);
    cout << "hello " << x << endl;
}

int main() {
    thread t1(f, 1);
    thread t2(f, 2);
    thread t3(f, 3);
    ts.push_back(std::move(t1));
    ts.push_back(std::move(t2));
    ts.push_back(std::move(t3));

    for (thread& t : ts) {
        t.join();
    }
}