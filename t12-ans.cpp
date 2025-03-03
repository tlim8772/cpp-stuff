// C++ program to iterated thorough
// all values. I equals number
// of values in tuple
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

// WARNING: C++17 or above required
template <size_t I = 0, typename... Ts>
constexpr void printTuple(tuple<Ts...> tup)
{
	// If we have iterated through all elements
	if constexpr (I == sizeof...(Ts)) {
        // Last case, if nothing is left to
        // iterate, then exit the function
        return;
    } else {
		// Print the tuple and go to next element
		cout << get<I>(tup) << " ";

		// Going for next element.
		printTuple<I + 1, Ts...>(tup);
	}
}

// Driver Code
int main()
{
	// Initialize the tuple
	tuple<string, string, string> tup("Geeks",
									"for",
									"Geeks");

	// Function call
	printTuple(tup);

	return 0;
}
