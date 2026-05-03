/**

   * Made by:    Diego Briaares
   * At:   23.10.2021 13:47:13
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int n, h;
int f, l;

bool vis[100000];

vector<int> edg[100000];

void dfs(int node) {
	if (vis[node]) return;
	vis[node] = true;
	for (auto w : edg[node]) {
		dfs(w);
	}
}

	int main () {
		optimize();
		cin >> n >> h;
		for (int i = 0; i < h; i++)	{
			int u, v;
			cin >> u >> v;
			u--, v--;
			edg[u].push_back(v);
			edg[v].push_back(u);
		}
		for (int i = 0; i < n; i++) {
			if (!vis[i] && !edg[i].empty()) {
				f++;
				dfs(i);
			}
		}
		for (int i = 0; i < n; i++) if (!vis[i]) l++;
		cout << f << " " << l << "\n";
	}