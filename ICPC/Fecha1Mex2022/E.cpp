/**

   * author:    Diego Briaares
   * At:   14.05.2022 15:15:37
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


class ModularInteger {
private:
	long long val = 0;
	long long MOD = (long long)1e9+7;

public:
	friend istream & operator >> (istream &in, ModularInteger &x);
	friend ostream & operator << (ostream &out, ModularInteger const &x);

	ModularInteger operator + (ModularInteger const &x) {
		ModularInteger res;
		res.val = val + x.val;
		if (res.val >= MOD) res.val -= MOD;
		return res;
	}		

	ModularInteger operator - (ModularInteger const &x) {
		ModularInteger res;
		res.val = val - x.val;
		if (res.val < 0) res.val += MOD;
		return res;
	}		

	ModularInteger operator * (ModularInteger const &x) {
		ModularInteger res;
		res.val = val * x.val;
		res.val %= MOD;
		return res;
	}

	ModularInteger binexp(ModularInteger &x, long long p) {
		if (p <= 0) {
			ModularInteger res;
			res.val = 1LL;
			return res;
		}
		if (p & 1LL) {
			ModularInteger res = binexp(x, p - 1);
			res = x * res;
			return res;
		}
		else {
			ModularInteger res = binexp(x, p >> 1);
			res = res * res;
			return res;
		}
	}

	ModularInteger operator / (ModularInteger &x) {
		ModularInteger res;
		res.val = val;
		res = res * binexp(x, MOD - 2);
		return res;
	}

	void operator += (ModularInteger const &x) {
		val = val + x.val;
		if (val >= MOD) val -= MOD;
	}

	void operator -= (ModularInteger const &x) {
		val = val - x.val;
		if (val < 0) val += MOD;
	}		

	void operator *= (ModularInteger const &x) {
		val = val * x.val;
		val %= MOD;
	}

	void operator /= (ModularInteger &x) {
		ModularInteger res;
		res.val = val;
		res = res * binexp(x, MOD - 2);
		val = res.val;
	}

	void operator = (long long x) {
		x %= MOD;
		if (x < 0) x += MOD;
		val = x;
	}

	ModularInteger operator + (long long x) {
		x %= MOD;
		if (x < 0) x += MOD;
		ModularInteger res;
		res.val = val + x;
		if (res.val >= MOD) res.val -= MOD;
		return res;
	}		

	ModularInteger operator - (long long x) {
		x %= MOD;
		if (x < 0) x += MOD;
		ModularInteger res;
		res.val = val - x;
		if (res.val < 0) res.val += MOD;
		return res;
	}		

	ModularInteger operator * (long long x) {
		x %= MOD;
		if (x < 0) x += MOD;
		ModularInteger res;
		res.val = val * x;
		res.val %= MOD;
		return res;
	}

	void operator += (long long x) {
		x %= MOD;
		if (x < 0) x += MOD;
		val = val + x;
		if (val >= MOD) val -= MOD;
	}

	void operator -= (long long x) {
		x %= MOD;
		if (x < 0) x += MOD;
		val = val - x;
		if (val < 0) val += MOD;
	}		

	void operator *= (long long x) {
		x %= MOD;
		if (x < 0) x += MOD;
		val = val * x;
		val %= MOD;
	}

	bool operator == (ModularInteger const &x) {
		return (bool)(val == x.val);
	}
	bool operator != (ModularInteger const &x) {
		return (bool)(val != x.val);
	}
};

istream & operator >> (istream &in, ModularInteger &x) {
	in >> x.val;
	return in;
}

ostream & operator << (ostream &out, ModularInteger const &x) {
	out << x.val;
	return out;
}

using Mint = ModularInteger;

vector<Mint> fact;

Mint comb(int n, int k) {
	if (fact.empty()) {
		Mint c;
		c = 1;		
		fact.push_back(c);
	}
	while ((int) fact.size() < n + 1) {
		Mint sz;
		sz = max(1LL, (long long) fact.size());
		fact.push_back(fact.back() * sz);
	}
	if (n < k) return fact[0];
	Mint inv;
	inv = fact[k] * fact[n - k];
	return fact[n] / inv;
}

const long long MOD = 1e9 + 7;
long long power(long long x, long long p) {
	if (p == 0) return 1;
	if (p & 1) {
		return (x * power(x, p - 1)) % MOD;
	}
	long long y = power(x, p / 2);
	return (y * y) % MOD;
}



	int main () {
		optimize();
		int n, m, k;
		cin >> n >> m >> k;
		if (k > n) {
			cout << "0\n";
			return 0;
		}
		Mint ans;
		ans = comb(m, k);
		ans *= fact[k];
		ans *= dp(0, k)

		cout << ans << "\n";
	}