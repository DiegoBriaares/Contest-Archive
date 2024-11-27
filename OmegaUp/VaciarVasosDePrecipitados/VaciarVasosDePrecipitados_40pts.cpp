/**

   * author:    Diego Briaares
   * At:   26.11.2024 13:52:47
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int v, w, n;
		cin >> v >> w >> n;
		vector<int> m(n + 1);
		m[n] = v;
		for (int i = 0; i < n; i++) {
		  cin >> m[i];
	  }	
	  int INF = 1e8;
		vector<pair<int, pair<int , int>>> dp(v + 1);
		for (int i = 0; i <= v; i++) {
			dp[i].first = INF;
		}
		dp[0].first = 0;
		for (int i = 0; i < v; i++) {
			for (int j = 0; j <= n; j++) {
				if (m[j] > i && v - i >= m[j]) {
					if (dp[m[j]].first > dp[i].first + 1) {
						dp[m[j]].first = dp[i].first + 1; 
						dp[m[j]].second.first = 1;
						dp[m[j]].second.second = m[j];
					}
				}
				if (m[j] < v - i && v - m[j] <= w) {
					if (dp[v - m[j]].first > dp[i].first + 1) {
						dp[v - m[j]].first = dp[i].first + 1;
						dp[v - m[j]].second.first = 2;
						dp[v - m[j]].second.second = v - i - m[j];
					}
				}				
				if (m[j] <= v - i && i + m[j] <= w) {
					if (dp[i + m[j]].first > dp[i].first + 2) {
						dp[i + m[j]].first = dp[i].first + 2;
						dp[i + m[j]].second.first = 3;
						dp[i + m[j]].second.second = m[j];
					}
				}
			}
		}
		for (int i = 1; i <= v; i++) {
			for (int j = 0; j < n; j++) {
				if (m[j] < i) {
					dp[i - m[j]].first = min(dp[i - m[j]].first, dp[i].first + 1);
				}
			}
		}
		if (dp[w].first == 1e8) {
			cout << "-1\n";
		}
		else {
			cout << dp[w].first << "\n";
			vector<vector<int>> ans;
			for (int i = 0; i < n; i++) {
				if (w + m[i] <= v && dp[w].first == dp[w + m[i]].first + 1) {
					vector<int> step;
					step.push_back(2);
					step.push_back(1);
					step.push_back(m[i]);
					ans.push_back(step);
					w += m[i];
					break;
				}
			}
			while (w > 0) {
				if (dp[w].second.first == 1) {
					vector<int> step;
					step.push_back(0);
					step.push_back(2);
					step.push_back(dp[w].second.second);
					ans.push_back(step);
					w -= dp[w].second.second;					
				}
				else if (dp[w].second.first == 2) {
					vector<int> step;
					step.push_back(0);
					step.push_back(2);
					step.push_back(dp[w].second.second);
					ans.push_back(step);
					w -= dp[w].second.second;					
				}
				else {
					assert(dp[w].second.first == 3);
					vector<int> step;
					step.push_back(1);
					step.push_back(2);
					step.push_back(dp[w].second.second);
					ans.push_back(step);
					vector<int> step2;
					step2.push_back(0);
					step2.push_back(1);
					step2.push_back(dp[w].second.second);
					ans.push_back(step2);
					w -= dp[w].second.second;					
				}
			}
			reverse(ans.begin(), ans.end());
			for (int i = 0; i < (int) ans.size(); i++) {
				cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
			}
		}
	}