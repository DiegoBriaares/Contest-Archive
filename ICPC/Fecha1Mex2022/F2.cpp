/**

   * author:    Diego Briaares
   * At:   14.05.2022 16:45:24
**/

#include <bits/stdc++.h>
using namespace std;

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

map<long long, long long> F;

long long f(long long n) {
	if (F.count(n)) return F[n];
	long long k= (n >> 1);
	if (!(n & 1LL)) {
		return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % MOD;
	} else { 
		return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % MOD;
	}
}

	int main () {
		optimize();
		F[0] = F[1] = 1;
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
		sort(h.begin(), h.end());
		long long ans = 1;
		for (int i = 1; i < (int) h.size(); i++) {
			if (h[i - 1] + 1 == h[i]) {
				cout << "0\n";
				return 0;
			}
			long long l = (h[i] - 1) - (h[i - 1] + 1);
			ans *= f(l);
			ans %= MOD;
		}
		cout << ans << "\n";
	}