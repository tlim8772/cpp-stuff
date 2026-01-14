#include <bits/stdc++.h>
using namespace std;

struct Serializable {
    virtual ~Serializable() {};
    virtual string to_string()  = 0;
};

struct Drawable {
    virtual ~Drawable() {};
    virtual void draw() = 0;
};

struct T: public Serializable, public Drawable {
    int t;

    T(int t): t(t) {}
    
    string to_string() override {
        return "I am " + std::to_string(t);
    }

    void draw() override {
        cout << "I am T and drawable" << endl;
    }
};

struct S: public Drawable {
    void draw() override {
        cout << "I am S and drawable" << endl;
    }
};


int main() {
    vector<unique_ptr<Drawable>> store;
    store.emplace_back(new T{10});
    store.emplace_back(new S{});

    for (auto& ptr : store) ptr->draw();

    vector<unique_ptr<Serializable>> store2;
    store2.emplace_back(new T{11});
    for (auto& p : store2) {
        cout << p->to_string() << endl;
    }
}