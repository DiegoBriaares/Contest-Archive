/**

   * Made by:    Diego Briaares
   * At:   17.02.2021 03:02:33
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int n, k;
		cin >> n >> k;       
		vector<int> a(n);
		for (int i = 1; i <= n; i++) cin >> a[i];
		vector<vector<int>> dp(n + 1, vector<int>(100000, 0));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= a[i]; j++) {
				dp[i][j] = 1;
			}
		}
		vector<int> acum(1000001, 0);
		for (int i = 1; i <= n; i++) {
			vector<int> new_acum(1000001, 0);
			for (int j = 1; j <= k; j++) {
				dp[i][j] += acum[j];
				if (j > a[i] + 1) dp[i][j] -= acum[j - a[i] - 1];
				new_acum[j] = new_acum[j - 1] + dp[i][j];
			}
			acum = new_acum;
		}
		cout << dp[n][k] << "\n";
	}