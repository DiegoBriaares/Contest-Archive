/**

   * Made by:    Diego Briaares
   * At:   29.09.2021 23:18:10
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

const int MAX = 1000001;
long long MOD = (int) 1e9 + 7;

long long dp[MAX];
long long pot[MAX];
long long ans[MAX];

	int main () {
		optimize();
		pot[0] = 1;
		for (int i = 1; i < MAX; i++) {
			pot[i] = (pot[i - 1] * 2) % MOD;
			dp[i] = (dp[i] + pot[i]) % MOD;
			for (int j = i + i; j < MAX; j += i) {
				dp[j] = (dp[j] - dp[i] + MOD) % MOD;
				ans[j] = (ans[j] + dp[i]) % MOD;
			}
		}
				
		int t;
		cin >> t;
		while (t--) {
			int k;
			cin >> k;
			if (k == 1) {
				cout << "0\n";
				continue;
			}
			cout << ans[k] << "\n";
		}
	}