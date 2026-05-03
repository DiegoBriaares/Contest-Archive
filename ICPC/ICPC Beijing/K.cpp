/**

   * Made by:    Diego Briaares
   * At:   05.11.2021 10:44:35
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
	//	optimize();
		int n, m;
		cin >> n >> m;
		vector<int> deg(n);
		for (int i = 0; i < m; i++)	{
			int u, v;
			cin >> u >> v;
			deg[u]++;
			deg[v]++;
		}
		vector<pair<int, int>> order;
		for (int i = 0; i < n; i++) order.push_back({deg[i], i});
		sort(order.begin(), order.end());
		int edges = 2 * m, ch = 0;
		for (int i = n - 1; i >= 0 && edges > 2 * (n - 1); i--) {
		    int rem = min(edges - 2 * (n - 1), (order[i].first - 1));
			edges -= rem;
			order[i].first -= rem;
			ch++;
		}
		sort(order.begin(), order.end());
		queue<int> leaves;
		int p = 0;
		while (p < n && order[p].first == 1) leaves.push(order[p++].second);
		vector<vector<int>> edg(n);
		while (p < n) {
			while (order[p].first > 1) {
				edg[order[p].second].push_back(leaves.front());
				leaves.pop();
				order[p].first--;
			}
			leaves.push(order[p++].second);
		}
		p--;
		while (order[p].first > 0) {
			edg[order[p].second].push_back(leaves.front());
			leaves.pop();
			order[p].first--;
		}
		cout << ch << "\n" << n << " " << n - 1 << "\n";
		for (int i = 0; i < n; i++) {
			for (auto s : edg[i]) cout << i << " " << s << "\n";
		}
	}
