#include <bits/stdc++.h>
using namespace std;


// problem: what if we want a function to accept types like vector<int>, unordered_set<float>
// this is the solution. We can now use the type of the elem (of the container) if needed
// template <typename> typename T> means that T can take in another template type
// so T<S> is acceptanble
template <template<typename> typename T, typename S>
void f(T<S> arr) {
    for (S s : arr) cout << s << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {1,2,3};
    vector<float> arr2 = {1.5,2.31,3.999};
    unordered_set<int> arr3 = {1,2,3};
    f<vector, int>(arr); // think of template as direct subsituition
    // why this does not work ?
    // f<vector<int>, int>(arr) because we do not have vector<int><int>
    f(arr2);
    f(arr3);
}