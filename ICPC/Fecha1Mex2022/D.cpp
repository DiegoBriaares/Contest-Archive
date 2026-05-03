/**

   * author:    Diego Briaares
   * At:   14.05.2022 14:48:51
**/

#include <bits/stdc++.h>
using namespace std;

istream & operator >> (istream &in, pair<int, int> &x) {
	in >> x.first >> x.second;
	return in;
}

ostream & operator << (ostream &out, pair<int, int> &x) {
	out << x.first << " " << x.second;
	return out;
}

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

const long long MOD = 1e9 + 7;

	int main () {
		optimize();
		int n, m, K;
		cin >> n >> m >> K;
		vector<vector<long long>> I(n, vector<long long>(n, 0)), ID(n, vector<long long>(n, 0));
		for (int i = 0; i < m; i++)	 {
			int u, v;
			cin >> u >> v;
			u--, v--;
			I[u][v]++;
			I[v][u]++;
		}
		auto prod = [&] (vector<vector<long long>> A, vector<vector<long long>> B) {
			vector<vector<long long>> R(n, vector<long long>(n, 0));
			for (int i = 0; i < n; i++) {
				ID[i][i] = 1;
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						R[i][j] += A[i][k] * B[k][j];
						R[i][j] %= MOD;
					}
				}
			}
			return R;
		};
		function<vector<vector<long long>>(int)> e = [&] (int p) -> vector<vector<long long>> {
			if (p == 0) return ID;
			if (p == 1) return I;
			vector<vector<long long>> H;
			if (p & 1) {
				H = e(p - 1);
				return prod(H, I);
			}
			else {
				H = e(p >> 1);
				return prod(H, H);
			}
		};
		vector<vector<long long>> RE = e(K);
		long long ways = 0;
		for (int i = 0; i < n; i++) {
			ways += RE[0][i];
			ways %= MOD;
		}
		cout << ways << "\n";
	}