#include <bits/stdc++.h>
using namespace std;

int f1() {
    return 1;
}
int f2() {
    return 2 * f1();
}



int main() {
    cout << f2() << endl;
}