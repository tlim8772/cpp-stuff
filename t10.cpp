#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l = 0, r = 0, sum = 0;
};

struct PST {
    int sz;
    Node *arr;

    PST() {};

    PST(int sz): sz(sz) {
        arr = new Node[sz];
    }

    ~PST() {
        delete[] arr;
    }

    void operator=(const PST&& other) {
        sz = other.sz;
        arr = other.arr;
        cout << "move assigned" << endl;
    }
    
    PST(const PST&& other) {
        sz = other.sz;
        arr = other.arr;
        cout << "moved constructed" << endl;
    }
};

struct T {
    PST pst;


    // we get a double free error 
    void f() {
        pst = PST(10); // when we do this, a temp object gets created, 
                       // and pst is moved assigned (in this case, sz, arr are just copied)
                       // when function call ends, compiler will call delete[] arr for the temp object
                       // when main endds, call delete[] arr (on the same ptr) so get double free error
    }

    void g() {
        cout << pst.arr[9].l << " " << pst.arr[9].r << " " << pst.arr[9].sum << endl;
    }

};



int main() {
    T t;
    t.f();
    t.g();
}