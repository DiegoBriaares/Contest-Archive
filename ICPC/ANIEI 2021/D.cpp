/**

   * Made by:    Diego Briaares
   * At:   23.10.2021 17:15:09
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1}; 

	int main () {
		optimize();
		int h, w, n;
		cin >> h >> w >> n;
		vector<vector<int>> M(h, vector<int>(w, 0));
		vector<vector<int>> cont(h, vector<int>(w, 0));
		vector<vector<int>> cont2(h, vector<int>(w, 0));
		for (int i = 0; i < n; i++)	{
			int x, y, d;
			cin >> x >> y >> d;
			x--, y--;
			cont2[x][y]++;
			queue<pair<int, pair<int, int>>> q;
			q.push({0, {x, y}});
			vector<vector<bool>> vis(h, vector<bool>(w, false));
			while (!q.empty()) {
				auto st = q.front();
				q.pop();
				int X = st.second.first, Y = st.second.second, S = st.first;
				if (vis[X][Y]) continue;
				vis[X][Y] = true;
				cont[X][Y]++;
				M[X][Y] += (S + d - 1) / d;
				for (int it = 0; it < 8; it++) {
					int nx = X + dx[it];
					int ny = Y + dy[it];
					if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
					q.push({S + 1, {nx, ny}});
				}
			}
		}
		int ans = 1000000;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (cont[i][j] >= n) {
					ans = min(ans, M[i][j]);
				}
			}
		}
		if (ans == 1000000) ans = -1;
		cout << ans << "\n";
	}