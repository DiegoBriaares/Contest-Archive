/**

   * Made by:    Diego Briaares
   * At:   05.03.2021 21:48:03
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

const int INF = 1e9 + 2;
int pos[1000000];

	int main () {
		optimize();
		int n, w, d;
		cin >> n >> w >> d;
		vector<vector<int>> edg(n + 1);
		for (int i = 0; i < w; i++)	{
			int a, b;
			cin >> a >> b;
			edg[b].push_back(a);
		}
		vector<int> path(n + 1, INF);
		auto dijk = [&] (int o) {
			multiset<pair<int, int>> q;
			q.insert({0, o});
			vector<bool> vis(n + 1);
			while (!q.empty()) {
				auto to = *q.begin();
				q.erase(q.begin());
				if (vis[to.second]) continue;
				vis[to.second] = true;
				path[to.second] = to.first;
				for (auto y : edg[to.second]) {
					q.insert({to.first + 1, y});
				}
		 	}
		};
		dijk(n);
		vector<int> S(n + 1);
		multiset<int> ans;
		for (int i = 1; i <= n; i++) {
			cin >> S[i];
			pos[S[i]] = i;
			if (path[S[i]] != INF) ans.insert((i - 1) + path[S[i]]);
		}
		while (d--) {
			int a, b;
			cin >> a >> b;
			if (path[S[a]] != INF) ans.erase(ans.find((pos[S[a]] - 1) + path[S[a]]));	
			if (path[S[b]] != INF) ans.erase(ans.find((pos[S[b]] - 1) + path[S[b]])); // && ans.find((pos[S[a]] - 1) + path[S[a]]) != ans.end()
			pos[S[a]] = b;
			pos[S[b]] = a;
			swap(S[a], S[b]);
			if (path[S[a]] != INF) ans.insert((pos[S[a]] - 1) + path[S[a]]);
			if (path[S[b]] != INF) ans.insert((pos[S[b]] - 1) + path[S[b]]);
			cout << *ans.begin() << "\n";
		}
	}
