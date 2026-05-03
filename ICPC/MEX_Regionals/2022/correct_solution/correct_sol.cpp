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

  
	int main () {
		int n;
		cin >> n;
		vector<pair<int, int>> a(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i + 1].first >> a[i + 1].second;
		}
		vector<int> order(n);
		iota(order.begin(), order.end(), 1);
		//order = {7, 5, 2, 1, 4, 6, 3};
		do
		{
			int sum = 0;
			bool ok = true;
			for (int i = 0; i < n; i++)	{
				sum += a[order[i]].first;
				if (sum > a[order[i]].second) {
				 ok = false;
				 break;
				}
			}
			if (ok) {
				for (int i = 0; i < n; i++) {
					cout << order[i] << " ";
				}
				cout << "\n";
				return 0;
			}
		} while (next_permutation(order.begin(), order.end()));
		cout << "*\n";
	}