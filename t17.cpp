#include <bits/stdc++.h>
#include <thread>
using namespace std;

void f() {
    cout << "hello" << endl;
}

void f2() {
    cout << "hello2" << endl;
}

int main() {
    thread t1(f);
    //t1.join();
    thread t3(f2);
    t1 = move(t3);
    t1.join();
}