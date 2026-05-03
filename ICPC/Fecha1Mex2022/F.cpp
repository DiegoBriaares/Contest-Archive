/**

   * author:    Diego Briaares
   * At:   14.05.2022 16:45:24
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
		long long n, m;
		cin >> n >> m;
		vector<long long> h;
		h.push_back(-1);
		h.push_back(n + 1);
		for (int i = 0; i < m; i++) {
			long long a;
			cin >> a;
			h.push_back(a);
		}
		vector<vector<long long>> I(2, vector<long long>(2, 0)), ID(2, vector<long long>(2, 0));
		ID[0][0] = ID[1][1] = 1;
		I[0][0] = I[0][1] = I[1][0] = 1;
		auto prod = [&] (vector<vector<long long>> A, vector<vector<long long>> B) {
			vector<vector<long long>> R(2, vector<long long>(2, 0));
			for (int i = 0; i < 2; i++) {
				ID[i][i] = 1;
				for (int j = 0; j < 2; j++) {
					for (int k = 0; k < 2; k++) {
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
		sort(h.begin(), h.end());
		long long ans = 1;
		for (int i = 1; i < (int) h.size(); i++) {
			if (h[i - 1] + 1 == h[i]) {
				cout << "0\n";
				return 0;
			}
			long long l = (h[i] - 1) - (h[i - 1] + 1);
			vector<vector<long long>> fib = e(l);
			ans *= fib[0][0];
		//	cout << "AUX: " << ans << " " << fib[1][0] << " " << l << "\n";
			ans %= MOD;
		}
		cout << ans << "\n";
	}