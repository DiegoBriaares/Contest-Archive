/**

   * author:    Diego Briaares
   * At:   14.05.2022 13:08:12
**/

#include <bits/stdc++.h>
using namespace std;

istream & operator >> (istream &in, pair<int, int> &x) {
	in >> x.first >> x.second;
	return in;
}

ostream & operator << (ostream &out, pair<int, int> &x) {
	out << x.first << " " << x.second;
	return out;
}

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int q, n;
		cin >> q >> n;
		vector<int> coin(n);
		for (int i = 0; i < n; i++)	cin >> coin[i];
		int MAX = 1e5 + 1;
		vector<int> dp(MAX);
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = coin[i]; j < MAX; j++) {
				dp[j] |= dp[j - coin[i]];
			}
		}
		set<int> a;
		for (int i = 0; i < MAX; i++) {
			if (dp[i]) a.insert(i);
		}
		while (q--) {
			int k;
			cin >> k;
			if (dp[k]) cout << "0\n";
			else {
				cout << *a.upper_bound(k) - k << "\n";
			}
		}
	}