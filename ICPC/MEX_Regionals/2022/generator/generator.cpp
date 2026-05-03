#include <bits/stdc++.h>
using namespace std;

	int main () {
		mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

		int n = uniform_int_distribution<int>(1, 12)(rng);
		cout << n << "\n";
		int max_deadline =  10 * n;
		vector<pair<int, int>> input;
		for (int i = 0; i < n; i++) {
			int t = uniform_int_distribution<int>(1, 10)(rng);
			int d = uniform_int_distribution<int>(1, max_deadline / 2)(rng);
      input.push_back(make_pair(t, d));
		}
		random_shuffle(input.begin(), input.end());
		for (int i = 0; i < n; i++) {
			cout << input[i].first << " " << input[i].second << "\n";
		}
	}