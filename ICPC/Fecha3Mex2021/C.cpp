/**

   * Made by:    Diego Briaares
   * At:   30.10.2021 13:17:32
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

long long power(long long x, long long p, long long MOD) {
	if (p == 0) return 1LL;
	if (p & 1) {
		return (x * power(x, p - 1, MOD)) % MOD;
	}
	long long y = power(x * x, p >> 1, MOD) % MOD;
	return ((y) % MOD);
}


	int main () {
		optimize();
		long long B, n;
		cin >> B >> n;
		vector<long long> dig(n);
		long long sum = 0;
		vector<long long> pot(n);
		pot[0] = 1;
		for (int i = 1; i < n; i++) {
			pot[i] = (pot[i - 1] * B) % (B + 1);
		}
		for (int i = 0; i < n; i++) {
			cin >> dig[i];
			sum += (dig[i] * pot[n - i - 1]) % (B + 1);
			sum %= (B + 1);
		}
		if (sum == 0) {
			cout << "0 0\n";
			return 0;
		}
		for (int i = 0; i < n; i++) {
			sum -= (dig[i] * pot[n - i - 1]) % (B + 1);
			if (sum < 0) {
				sum += B + 1;
				sum %= (B + 1);
			}
			if (sum == 0) {
				cout << i + 1 << " 0\n";
				return 0;
			}
			long long r = (((sum) % (B + 1)) * power(pot[n - i - 1], B - 1, B + 1)) % (B + 1);
			r *= (-1);
			r += B + 1;
			r %= (B + 1);
			if (i == 12560 - 1) cout <<"yeah " << r << " " << dig[i] << " " << (r * pot[n - i - 1] + sum) % (B + 1) << "\n";
			if (r < dig[i] && (((r * pot[n - i - 1]) % (B + 1)) + sum) % (B + 1) == 0) {
				cout << i + 1 << " " << r << "";
				return 0;
			}
			sum += (dig[i] * pot[n - i - 1]) % (B + 1);
			sum %= (B + 1);
		}
		cout << "-1 -1\n";
	}