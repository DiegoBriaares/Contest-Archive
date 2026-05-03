/**

   * Made by:    Diego Briaares
   * At:   30.10.2021 16:10:04
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

const int MAX = 1e6;

int bit[MAX];

void update(int i, int v) {
	while (i < MAX) {
		bit[i] += v;
		i += (i & -i);
	}
}

int query(int i) {
	int r = 0;
	while (i > 0) {
		r += bit[i];
		i -= (i & -i);
	}
	return r;
}

	int main () {
		optimize();
		int Y, n;
		cin >> Y >> n;
		vector<pair<int, int>> x(Y + 1);
		vector<int> X(Y + 1);
		for (int i = 1; i <= Y; i++)	{
			cin >> x[i].first;
			x[i].second = i;
			X[i] = x[i].first;
		}
		vector<pair<pair<int, int>, pair<int, int>>> p(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> p[i].second.first >> p[i].first.first >> p[i].second.second;
			p[i].first.second = i;
		}
		x[0].first = MAX;
		sort(x.rbegin(), x.rend());
		sort(p.rbegin(), p.rend());
		int pos = 0;
		vector<int> ans(n, 0);
		for (int i = 1; i <= Y; i++) {
			if (pos >= n) break;
			while (pos < n && p[pos].first.first > x[i].first) {
				if (X[p[pos].second.first] < p[pos].first.first) {
					ans[p[pos].first.second] = query(p[pos].second.first + p[pos].second.second) - query(p[pos].second.first);
				}
				pos++;
			}
			update(x[i].second, 1);
		}
	
		for (int i = 0; i < n; i++) cout << ans[i] << "\n";
	}