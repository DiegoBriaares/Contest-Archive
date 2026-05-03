#include <bits/stdc++.h>
using namespace std;

	int main () {
		mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
		int n = uniform_int_distribution<int>(1, 20)(rng);
		for (int i = 0; i < n; i++) {
			char c = (char) ((uniform_int_distribution<int>(0, 25)(rng)) + 'a');
			cout << c;
		}
		cout << "\n";
	}