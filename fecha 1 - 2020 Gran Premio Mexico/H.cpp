/**

   * Made by:    Diego Briaares
   * At:   16.02.2021 21:57:31
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int n;
int a[52];

void test_case() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> dp(n + 3);
	for (int i = 1; i <= n; i++) {
		dp[i + 1] = max(dp[i + 1], dp[i]);
		dp[i + 2] = max(dp[i + 2], dp[i] + a[i]);
	}
	cout << *max_element(dp.begin(), dp.end()) << "\n";
}

	int main () {
		optimize();
		int t;
		cin >> t;
		while (t--) {
			test_case();

		}
	}