/**

   * author:    Diego Briaares
   * At:   14.05.2022 13:55:34
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
		int n, m;
		cin >> n >> m;
		vector<int> sz(n), dmd(m);
		vector<vector<int>> rich(n), city(m);
		for (int i = 0; i < n; i++)	{
			cin >> sz[i];
			for (int j = 0; j < sz[i]; j++) {
				int c;
				cin >> c;
				c--;
				rich[i].push_back(c);
				city[c].push_back(i);
				dmd[c]++;
			}
		}
		set<pair<int, int>> R;
		for (int i = 0; i < n; i++) {
			R.insert(make_pair(sz[i], i));
		}
		vector<int> upd(n, 0);
		while (!R.empty()) {
			auto t = *R.begin();
			R.erase(R.begin());
			if (upd[t.second]) {
				sz[t.second] -= upd[t.second];
				upd[t.second] = 0;
				if (sz[t.second] > 0) {
					R.insert(make_pair(sz[t.second], t.second));
					continue;
				}
			}
			if (t.first <= 0) continue;
			int c = 0, d = n + 1;
			for (auto ct : rich[t.second]) {
				if (dmd[ct] < d && dmd[ct] > 0) {
					d = dmd[ct];
					c = ct;
				}
			}
			if (d == n + 1) continue;
			dmd[c] = 1;
			for (auto ct : rich[t.second]) {
				dmd[ct]--;
			}
			for (auto r : city[c]) {
				upd[r]++;
			}
			m--;
		}
		cout << m << "\n";
	}