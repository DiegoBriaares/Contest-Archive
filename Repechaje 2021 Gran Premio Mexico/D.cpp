/**

   * Made by:    Diego Briaares
   * At:   13.02.2021 15:41:45
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int criba[1000001];
vector<long long>primes;
long long K;

long long power(int x, int p, int P) {
	if (p == 0) return 1;
	if (p & 1) {
		return (x * power(x, p - 1, P) % P);
	}
	long long po = power(x, p / 2, P);
	return (po * po) % P;
}

bool ok (int p) {
	if ((power(2, p - 1, p) + K) % p == 0) return true;
	return false;
}
void test_case() {
	cin >> K;
	vector<int> ans;
	for (int j = 0; j < primes.size(); j++) {
		if (((1 << primes[j]) + K) > 0 && ((1 << primes[j]) + K) % primes[j]) ans.push_back(primes[j]);
	}
	sort(ans.begin(), ans.end());
	if (ans.empty()) {
		cout << "-1\n";
		return;
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i + 1 < ans.size()) cout << " ";
		else cout << "\n";
	}
}

	int main () {
		optimize();
		for (int i = 2; i < 1000001; ) {
			if (!criba[i]) {
				for (int j = i + i; j < 1000001; j += i) {
					criba[j] = true;
				}
				if (i != 2) primes.push_back(i);
			}
			if (i == 2) i++;
			else i += 2;
		}
		int t;
		cin >> t;
		while (t--) {
			test_case();

		}
	}