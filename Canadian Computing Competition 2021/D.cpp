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
vector<vector<int>> edg;
int S[1000000];
vector<int> path;
multiset<int> ans;
bool vis[1000000];
multiset<pair<int, int>> q;

	int main () {
		optimize();
		int n, w, d;
		cin >> n >> w >> d;
		edg.resize(n + 1);
		for (int i = 0; i < w; i++)	{
			int a, b;
			cin >> a >> b;
			edg[b].push_back(a);
		}
		path.resize(n + 1, INF);
		auto dijk = [&] (int o) {
			q.insert({0, o});
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
		for (int i = 1; i <= n; i++) {
			cin >> S[i];
			pos[S[i]] = i;
			if (path[S[i]] != INF) ans.insert((i - 1) + path[S[i]]);
		}
		while (d--) {
			int a, b;
			cin >> a >> b;
			if (path[S[a]] != INF) ans.erase(ans.find((pos[S[a]] - 1) + path[S[a]]));	
			if (path[S[b]] != INF) ans.erase(ans.find((pos[S[b]] - 1) + path[S[b]])); 
			pos[S[a]] = b;
			pos[S[b]] = a;
			swap(S[a], S[b]);
			if (path[S[a]] != INF) ans.insert((pos[S[a]] - 1) + path[S[a]]);
			if (path[S[b]] != INF) ans.insert((pos[S[b]] - 1) + path[S[b]]);
			cout << *ans.begin() << "\n";
		}
	}