#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Base
{
    int id = 0;
    static int sid;

    Base(int x): id(x) {}
    
    void baseMethod()
    {
        std::cout << "Base<T>::f()\n";
    }

    static void staticBaseMethod() {
        cout << sid << endl;
        std::cout << "staticBaseMethod\n";
    }
};

template <typename T>
int Base<T>::sid = 69;



template <typename T>
struct Derived : Base<T>
{   
    Derived(): Base<T>(10) {}

    void derivedMethod() 
    {
        std::cout << "Derived<T>::g()\n  ";


        /**
         * ERROR: Dependent Name (as there is no baseMethod() in derived class): Call to baseMethod() depends
         * on Base class template hence compiler is not aware of baseMethod().
         */
        Base<T>::baseMethod();
        Base<T>::staticBaseMethod();
        f(); // Non dependent Name: hence no issues here
    }


    void f()
    {


    }
};


int main()
{
    Derived<int> d{};
    d.derivedMethod();
    return 0;
}
