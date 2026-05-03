/**

   * Made by:    Diego Briaares
   * At:   20.10.2021 16:51:49
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

const int MAX = 5 * (int) 1e5 + 2;


int bad[MAX];
set<int> edg[MAX];

set<pair<int, int>> dead;

bool ok;
vector<int> tree;

void dfs(int dad, int node) {
	bad[node]++;
	if (bad[node] > 1) ok = false;
	if (bad[node] > 1) return;
	tree.push_back(node);
	for (auto w : edg[node]) {
		if (w != dad) {
			dfs(node, w);
		}
	}
}

	int main () {
		optimize();
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			edg[u].insert(v);
			edg[v].insert(u);
		}
		for (int i = 0; i < n; i++) {
			if (!bad[i]) {
				ok = true;
				tree.clear();
				dfs(n, i);
				if (ok) {
					for (int it = 0; it < (int) tree.size(); it++) {
						for (auto w : edg[tree[it]]) {
							if ((int)edg[w].size() == 1) {
								dead.insert({w, tree[it]});
							}
						}
					}
				}
			}
		}
		memset(bad, 0, sizeof(bad));
		queue<int> leaves;
		for (int i = 0; i < n; i++) {
			if ((int) edg[i].size() == 1) {
				leaves.push(i);
			}
		}
		while (!leaves.empty()) {
			int l = leaves.front();
			leaves.pop();
			if (edg[l].empty()) {
				bad[l] = true;
				continue;
			}
			for (auto w : edg[l]) {
				if (edg[w].find(l) != edg[w].end()) {
					edg[w].erase(edg[w].find(l));
					bad[l] = true;
				}
				if ((int) edg[w].size() == 1) {
					leaves.push(w);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (auto w : edg[i]) {
				if (bad[i] && !bad[w]) dead.insert({w, i});
			}
		}       
		cout << (int) dead.size() << "\n";
		for (auto d : dead) cout << d.first + 1 << " " << d.second + 1 << "\n";
	}