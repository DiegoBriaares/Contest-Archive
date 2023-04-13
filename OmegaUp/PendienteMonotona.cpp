/**

   * author:    Diego Briaares
   * At:   12.04.2023 19:57:51
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int INF = (1 << 30);

	int main () {
		optimize();
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i + 1];
		}	
		int min_cost = INF;
		vector<int> ord = a;
		sort(ord.begin(), ord.end());
		vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    auto Fill = [&] () {
    	for (int i = 0; i <= n; i++) {
    		for (int j = 0; j <= n; j++) {
    			if (i == 0) {
    				dp[i][j] = 0;
    			}
    			else {
    				dp[i][j] = INF;
    			}
    		}
    	}
    };
		auto solve = [&] () {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					dp[i][j] = dp[i][j - 1];
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + abs(a[i] - ord[j]));
				}
			}
		};
		Fill();
		solve();
		min_cost = min(min_cost, dp[n][n]);
		reverse(ord.begin(), ord.end());
		Fill();
		solve();
		min_cost = min(min_cost, dp[n][n]); 
		cout << min_cost << "\n";
	}

