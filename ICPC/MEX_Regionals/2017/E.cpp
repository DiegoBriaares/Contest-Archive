/**

   * author:    Diego Briaares
   * At:   01.04.2022 19:54:36
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


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		string s;
		while (cin >> s) {
			int n = s.size();
			int k;
			cin >> k;
			vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>> (k, make_pair(0, 0)));
			dp[0][0].first = 1;
			vector<int> pot(n + 1);
			pot[0] = 1;
			for (int i = 1; i <= n; i++) {
				pot[i] = (pot[i - 1] * 10) % k;
			}
			for (int i = 1; i <= n; i++) {
				for (int r = 0; r < k; r++) {
					if (s[i - 1] != '?') {
						int nxt = (r + pot[n - i] * (s[i - 1] - '0')) % k;
						if (dp[i - 1][r].first) {
							dp[i][nxt].first = 1;
							dp[i][nxt].second = s[i - 1] - '0';
						}
					}
					else {
						for (int d = 0; d < 10; d++) {
							if (i == 1 && d == 0) continue;
							int nxt = (r + pot[n - i] * d) % k;
							if (dp[i - 1][r].first) {
								dp[i][nxt].first = 1;
								dp[i][nxt].second = min(dp[i][nxt].second, d);
							}
						}
					}
				}
			}
			if (dp[n][0].first == 0) {
				cout << "*\n";
				continue;
			}
			else {
				vector<int> ans(n);
				int r = 0;
				for (int i = n - 1; i >= 0; i--) {
					ans[i] = dp[i + 1][r].second;
					r = (r - ans[i] + ans[i] * k) % k;
					cout << "AUX: " << r << "\n";
				}
				for (int i = 0; i < n; i++) {
					cout << ans[i];
				}
				cout << "\n";
			}
		}
	}