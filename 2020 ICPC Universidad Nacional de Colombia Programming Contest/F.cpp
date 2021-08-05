/**

   * Made by:    Diego Briaares
   * At:   12.02.2021 02:35:43
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

const int INF = 1e9;

	int main () {
		optimize();
		int n, m;
		cin >> n >> m;
		int a, b, k;
		cin >> a >> b >> k;
		vector<vector<pair<int, int>>> edg(n + 1), iedg(n + 1);
		for (int i = 0; i < m; i++)	 {
			int u, v, w;
			cin >> u >> v >> w;
			edg[u].push_back({v, w});
			iedg[v].push_back({u, w});
		}
		vector<multiset<int>> kfa(n + 1), kfb(n + 1);
		vector<int> costsa(n + 1, INF), costsb(n + 1, INF);
		auto dijk = [&] (int o) {
			multiset<pair<pair<int, int>, multiset<int>>> q;
			multiset<int> st;
			q.insert({{0, o}, st});
			while (!q.empty()) {
				pair<pair<int, int>, multiset<int>> t = *q.begin();
				q.erase(q.begin());
			//	cout << "Origin: "<< o << " city " << t.first.second << " with cost " << t.first.first << " and size " << t.second.size() << "\n";
				if (o == a) {
					if (costsa[t.first.second] != INF) continue;
					costsa[t.first.second] = t.first.first;
					kfa[t.first.second] = t.second;
				}
				if (o == b) {
					if (costsb[t.first.second] != INF) continue;
					costsb[t.first.second] = t.first.first;
					kfb[t.first.second] = t.second;
				}

				for (auto x : edg[t.first.second]) {
					st = t.second;
					st.insert(x.second);
					if (st.size() > k) st.erase(st.begin());
					q.insert({{(x.second + t.first.first), x.first}, st});
				}
			}
			return;
		};
		vector<multiset<int>> ikfa(n + 1), ikfb(n + 1);
		vector<int> icostsa(n + 1, INF), icostsb(n + 1, INF);
		auto idijk = [&] (int o) {
			multiset<pair<pair<int, int>, multiset<int>>> q;
			multiset<int> st;
			q.insert({{0, o}, st});
			while (!q.empty()) {
				pair<pair<int, int>, multiset<int>> t = *q.begin();
				q.erase(q.begin());
			//	cout << "IOrigin: "<< o << " city " << t.first.second << " with cost " << t.first.first << " and size " << t.second.size() << "\n";
				if (o == a) {
					if (icostsa[t.first.second] != INF) continue;
					icostsa[t.first.second] = t.first.first;
					ikfa[t.first.second] = t.second;
				}
				if (o == b) {
					if (icostsb[t.first.second] != INF) continue;
					icostsb[t.first.second] = t.first.first;
					ikfb[t.first.second] = t.second;
				}

				for (auto x : iedg[t.first.second]) {
					st = t.second;
					st.insert(x.second);
					if (st.size() > k) st.erase(st.begin());
					q.insert({{(x.second + t.first.first), x.first}, st});
				}
			}
			return;
		};
		dijk(a);
		dijk(b);
		idijk(a);
		idijk(b);
		auto disc = [&] (int o, int c) {
			int sum = 0;
			priority_queue<int> cost;
			if (o == a) {
				for (auto it = kfa[c].begin(); it != kfa[c].end(); it++) {
					cost.push(*it);
				}
				for (auto it = ikfa[c].begin(); it != ikfa[c].end(); it++) {
					cost.push(*it);
				}
			}
			if (o == b) {
				for (auto it = kfb[c].begin(); it != kfb[c].end(); it++) {
					cost.push(*it);
				}
				for (auto it = ikfb[c].begin(); it != ikfb[c].end(); it++) {
					cost.push(*it);
				}
			}
			for (int i = 0; i < k && !cost.empty(); i++) {
				sum += cost.top();
				cost.pop();
			}
			return sum;
		};
		int ans = INF, city = 1;
		for (int i = 0; i < n; i++) {
			if (costsa[i] == INF || costsb[i] == INF || i == a || i == b || icostsa[i] == INF || icostsb[i] == INF) continue;
			if (ans > costsa[i] + costsb[i] + icostsa[i] + icostsb[i] - disc(a, i) - disc(b, i)) {
				ans = costsa[i] + costsb[i] + icostsa[i] + icostsb[i] - disc(a, i) - disc(b, i);
				city = i;
			}
		}
		if (ans != INF) cout << city << " " << ans << "\n";
		else cout << ">:(\n";
	}