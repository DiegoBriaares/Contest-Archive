/**

   * Made by:    Diego Briaares
   * At:   13.08.2021 15:05:31
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

const int INF = 1e9 + 7;
int n, SUM;
int a[1002];
	int main () {
		optimize();
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			SUM += a[i];
		}                                            
		vector<vector<int>> dp(2, vector<int>(n + 2, INF));
		dp[1][0] = dp[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 2; j++) {
				if (j && i == 1) continue;
				if (j) {
					dp[j][i] = min(dp[j][i], dp[0][i - 1] + abs(a[i] - a[i - 1]));
				}
				else {
					dp[j][i] = min(dp[j][i], dp[1][i - 1]);
				}
			}
		}
		cout << dp[1][n] << "\n";
	}