/**

   * author:    Diego Briaares
   * At:   12.09.2022 23:07:39
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true" : "false"); 
}                                  

string to_string(vector<bool> v) {
	string s = "{";
	bool in = true;
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!in) {
			s += ", ";
		}
		in = false;
		s += to_string(v[i]);
	}
	s += "}";
	return s;
}

template <typename A>
string to_string(A v) {
	string s = "{";
	bool in = true;
	for (const auto &x : v) {
		if (!in) {
			s += ", ";
		}
		in = false;
		s += to_string(x);
	}
	s += "}";
	return s;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() {
	cerr << "\n";
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL 
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)	
#else
#define debug(...) 46
#endif


const long long MOD = 1e9 + 7;

map<long long, long long> F;

long long f(long long n) {
	if (n <= 1) return 1;
	if (F.count(n)) return F[n];
	long long k = (n >> 1);
	if (!(n & 1LL)) {
		return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % MOD;
	} else { 
		return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % MOD;
	}
}



	int main () {
		optimize();
		int n, m;
		cin >> n >> m;
		vector<bool> hole(n + 1, false);
		for (int i = 0; i < m; i++)	{
			int p;
			cin >> p;
			hole[p] = true;
		}
		int sz = 0;
		long long ways = 1;
		for (int i = 1; i <= n; i++) {
			if (hole[i]) {
				if (hole[i + 1]) {
					ways = 0;
				}
				debug(sz);
				ways *= f(sz - 1);
				ways %= MOD;
				sz = 0;
			}
			else {
				sz++;
			}
		}
		debug(sz);
		ways *= f(sz - 1);
		ways %= MOD;
		cout << ways << "\n";
	}