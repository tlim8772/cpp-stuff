#include <utility>
#include <bits/stdc++.h>
using namespace std;

template <typename F>
auto make_wrapper(F f) {
    return [x = make_shared<int>(0), f](auto&&... args) mutable -> decltype(auto) {
        cout << "function called " << ++(*x) << " times" << endl;
        return f(std::forward<decltype(args)>(args)...);
    };
}

template <typename F>
auto make_wrapper2(F f) {
    return [x = 0, f](auto&&... args) mutable -> decltype(auto) {
        cout << "function called " << ++x << " times" << endl;
        return f(std::forward<decltype(args)>(args)...);
    };
}

auto add = [] (int x, int y) { return x + y; };

int main() {
    auto f = make_wrapper(add);
    f(1, 2);
    f(2, 3);

    auto g = f;
    g(10, 3);
    f(1, 2);

    function<int(int,int)> h = f;
    h(3, 4);
}
