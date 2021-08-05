/**

   * Made by:    Diego Briaares
   * At:   11.02.2021 00:36:48
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		string a, b;
		cin >> a >> b;
		char m = 'a';
		for (int i = 0; i < a.size(); i++)	{
			m = max(m, a[i]);
		}
		auto get = [&] (char t, string s) {
			queue<pair<int, int>> q;
			vector<bool> vis(s.size(), 0), ph(s.size(), 0);
			string name;
			name.push_back(t);
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == t) {
					q.push({i, i});
					vis[i] = true;
				}
			}
			while (name.size() < s.size()) {
				vector<pair<int, int>> next;
				char to = 'a';
				while (!q.empty()) {
					pair<int, int> g = q.front();
					q.pop();
					g.first++;
					if (g.first >= s.size()) continue;
					to = max(to, s[g.first]);
					if (vis[g.first]) ph[g.first] = true;
					next.push_back(g);
				}
				for (int i = 0; i < next.size(); i++) {
					if (!ph[next[i].second] && to == s[next[i].first]) {
						q.push(next[i]);
					}
				}
				if (next.empty()) break;
				name.push_back(to);
			}
			return name;
		};
		string x = get(m, a);
		m = 'a';
		for (int i = 0; i < b.size(); i++)	{
			m = max(m, b[i]);
		}
		string y = get(m, b), ans;
		ans.push_back(x[0]);
		for (int i = 1; i < x.size(); i++) {
			if (x[i] < y[0]) {
				cout << ans + y << "\n";
				return 0;
			}
			else {
				ans.push_back(x[i]);
			}
		}
		cout << ans + y << "\n";
	}