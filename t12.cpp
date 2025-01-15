#include <iostream>
#include <tuple>
using namespace std;

template <int idx = 0, typename... T>
constexpr void printTuple(tuple<T...> tuple) {
    
    if constexpr (idx == sizeof...(T)) {
        cout << endl;
        return;
    } else {
        cout << get<idx>(tuple) << " ";
        printTuple<idx + 1, T...>(tuple);
    }
}

int main() {
    tuple<int, int, char> t1 = {12,13, 'c'};
    tuple<char, char, char, int> t2 = {'a', 'b', 'c', 1};
    printTuple(t1);
    printTuple(t2);
}