/**

   * Made by:    Diego Briaares
   * At:   25.09.2021 12:05:51
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int n, m;
bool vis[1001][1001];
char g[1001][1001];
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

	int main () {
		optimize();
		cin >> n >> m;
		queue<pair<int, pair<int, int>>> q;
		for (int i = 0; i < n; i++)	{
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
			}
		}
		int ans = 0;
		for (int l = 'A'; l <= 'Z'; l++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (g[i][j] == (char) l) {
						q.push({1, {i, j}});
					}
				}
			}
			memset(vis, 0, sizeof(vis));
			while (!q.empty()) {
				auto t = q.front();
				q.pop();
				ans = max(ans, t.first);
				int x = t.second.first, y = t.second.second;
				if (vis[x][y]) continue;
				vis[x][y] = true;
				for (int it = 0; it < 8; it++) {
					int A = x + dx[it], B = y + dy[it];
					if (A < 0 || A >= n || B < 0 || B >= m) continue;
					if (g[A][B] == (char) (g[x][y] + 1)) q.push({t.first + 1, {A, B}});
				}
			}
			}
			cout << ans << "\n";
	}