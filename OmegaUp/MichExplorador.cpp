/**

   * author:    Diego Briaares
   * At:   19.12.2024 18:03:24
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

#define type pair<pair<int, int>, pair<int, int>>
#define co first.first
#define sy first.second
#define x second.first
#define y second.second

type mp(int a, int b, int c, int d) {
	return make_pair(make_pair(a, b), make_pair(c, d));
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

	int main () {
		optimize();
		int n, m;
		cin >> n >> m;
		vector<vector<int>> A(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> A[i][j];
			}
		}
		set<type> S;
		S.insert(mp(0, 0, n - 1, 0));
		vector<vector<int>> vis(n, vector<int>(m, 0));
		vector<vector<int>> symb(n, vector<int>(m, 0));
		int ans = n * m + 1;
		while (!S.empty()) {
			type act = *S.begin();
			S.erase(act);
			if (vis[act.x][act.y]) {
				continue;
			}
			vis[act.x][act.y] = 1;
			symb[act.x][act.y] = act.sy;
			if (act.x == 0 && act.y == m - 1) {
				ans = act.co;
				break;
			}
			for (int i = 0; i < 4; i++) {
				if (i == A[act.x][act.y]) {
					if (act.x + dx[i] < n && act.x + dx[i] >= 0 &&
							act.y + dy[i] < m && act.y + dy[i] >= 0) {
						S.insert(mp(act.co, i, act.x + dx[i], act.y + dy[i]));			
					}
				}
				else {
					if (act.x + dx[i] < n && act.x + dx[i] >= 0 &&
							act.y + dy[i] < m && act.y + dy[i] >= 0) {							
						S.insert(mp(act.co + 1, i, act.x + dx[i], act.y + dy[i]));			
					}					
				}
			}
		}
		cout << ans << "\n";
		int xf, yf;
		xf = 0;
		yf = m - 1;
		int cnt = 0;
		while (!(xf == n - 1 && yf == 0)) {
			int new_xf = xf - dx[symb[xf][yf]];
			int new_yf = yf - dy[symb[xf][yf]];
			if (A[new_xf][new_yf] != symb[xf][yf]) {
				cnt++;
			}
			A[new_xf][new_yf] = symb[xf][yf];
			xf = new_xf;
			yf = new_yf;
		}
		assert(cnt == ans);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << A[i][j] << " ";
			}
			cout << "\n";
		}

	}