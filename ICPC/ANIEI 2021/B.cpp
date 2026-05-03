/**

   * Made by:    Diego Briaares
   * At:   23.10.2021 15:15:09
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

long long ans[2002];

long long MOD = (long long) 1e9 + 7;

bool prime(int x) {
	int y = sqrt(x);
	while (y > 1) {
		if (x % y == 0) return 0;
		y--;
	}
	return true;
}

long long expo(long long x, int e) {
	if (e == 0) return 1LL;
	if (e & 1) {
		return (x * expo(x, e - 1)) % MOD;
	}
	else return (expo((x * x) % MOD, e / 2)) % MOD;
}

long long fact[2001];

long long comb(int n, int k) {
	long long c = fact[n];
	c *= (expo((fact[k] * fact[n - k]) % MOD, MOD - 2));
	c %= MOD;
	return c;
}

	int main () {
		optimize();
		set<int> primes;
	    for (int i = 2; i < 2002; i++) {
	    	if (prime(i)) primes.insert(i);
	    }
	    fact[0] = 1;
	    for (int i = 1; i < 2001; i++) fact[i] = (fact[i - 1] * (long long) i) % MOD;
	    for (int l = 1; l < 2001; l++) {
	    	ans[l] = ans[l - 1];
	    	for (auto p : primes) {
	    		if (p >= l) break;
	    		if (primes.find(l - p) != primes.end()) {
	    			ans[l] += comb(l, p);
	    			ans[l] %= MOD;
	    		}
	    	
	    	}
	    }
	    int Q;
	    cin >> Q;
	    while (Q--) {
	    	int X, Y;
	    	cin >> X >> Y;
	    	long long R = ans[Y] - ans[X - 1];
	    	R += MOD;
	    	R %= MOD;
			cout << R << "\n";
	    }
	}