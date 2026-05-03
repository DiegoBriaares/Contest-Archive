/**

   * Made by:    Diego Briaares
   * At:   03.10.2021 19:51:01
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

bool dp[500000001][2];

bool bad(int x) {
	int c = 0;
	for (int i = 0; i < 30; i++) c += min(1, (x & (1 << i)));
	return (c & 1);
}

	int main () {
		optimize();
		int n, m;
		cin >> n >> m;
		int sa = 0, sb = 0, tot = 0;
		for (int i = 1; i <= min(n, m); i++) {
			if (bad(n - i)) continue;
			dp[n - i][0] = true;	
			sa++;
			tot++;
		}
		for (int i = n - m - 1; i >= 0; i--) {
			if (sa < tot) dp[i][1] = false;
			else dp[i][1] = true;
			if (sb > 0) dp[i][0] = true;
			else dp[i][0] = false;
			if (bad(i)) {
				dp[i][1] = dp[i][0] = false;
			}
			else tot++;
			if (i + m <= n && !(bad(i + m))) tot--;
			sa += (int) dp[i][0];
			if (i + m <= n) sa -= (int) dp[i + m][0];
			sb += (int) dp[i][1];
			if (i + m <= n) sb -= (int) dp[i + m][1];
		}
		if (dp[0][0]) cout << "Pay the bill\n";
		else cout << "Free snacks!\n";
	}