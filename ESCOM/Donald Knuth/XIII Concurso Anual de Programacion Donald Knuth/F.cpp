/**

   * Made by:    Diego Briaares
   * At:   13.08.2021 16:48:34
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
	return "(" + to_string(p.first) << ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) << ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) << ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
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



void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		long long int n, m;
		cin >> n >> m;
		vector<pair<long long int, long long int>> patch(m + 1);
		for (int i = 0; i < m; i++)	cin >> patch[i].first >> patch[i].second;
		function<bool(long long int)> check = [&] (long long int t) {
			long long int xU = patch[0].first - t;
			long long int xL = patch[0].second - t;
			long long int xR = patch[0].second + t;
			long long int xD = patch[0].first + t; 
			for (int i = 1; i < m; i++) {
				xU = min(xU, patch[i].first - t);
				xL = min(xL, patch[i].second - t);
				xR = max(xR, patch[i].second + t);
				xD = max(xD, patch[i].first + t);
				//debug(xU, xR, xL, xD);
			}
			if (xU <= 1 && xD >= n && xL <= 1 && xR >= n) return true;
			return false;
		};
		long long int l = 0, r = 1e18, mid = -1, days = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (check(mid)) {
				days = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		cout << days << "\n";
	}