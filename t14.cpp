#include <bits/stdc++.h>
using namespace std;


// problem: what if we want a function to accept types like vector<int>, unordered_set<float>
// this is the solution. We can now use the type of the elem (of the container) if needed
template <template<typename> typename H, typename S>
void f(H<S> arr) {
    for (S s : arr) cout << s << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {1,2,3};
    vector<float> arr2 = {1.5,2.31,3.999};
    unordered_set<int> arr3 = {1,2,3};
    f(arr);
    f(arr2);
    f(arr3);
}