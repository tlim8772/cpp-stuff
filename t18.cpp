#include <thread>
#include <iostream>
using namespace std;

void f() {
    cout << this_thread::get_id() << endl;
}

int main() {
    thread t1(f), t2(f);
    t1.join(); t2.join();
}