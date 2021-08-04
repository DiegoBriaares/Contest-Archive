/**

   * Made by:    Diego Briaares
   * At:   04.08.2021 00:03:39
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int n;
		cin >> n;
		vector<int> roots;
		vector<vector<int>> edg(n);
		for (int i = 0; i < n; i++)	{
			int p;
			cin >> p;
			if (p == i + 1) roots.push_back(i);
			else  edg[p - 1].push_back(i);
		}
		vector<int> ans(n, -1);
		int curr = -1;
		function<void(int)> mark = [&] (int v) {
			ans[v] = curr;
			for (auto u : edg[v]) mark(u);
		};
		for (auto r : roots) {
			curr = r;
			mark(r);
		}
		for (int i = 0; i < n; i++) cout << ans[i] + 1 << (i + 1 < n ? " " : "\n");
	}