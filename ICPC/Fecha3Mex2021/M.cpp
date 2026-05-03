/**

   * Made by:    Diego Briaares
   * At:   30.10.2021 12:32:09
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

const int MAX = (int) 1e5 + 10;

	int main () {
		optimize();
		int q;
		cin >> q;
		vector<set<int>> edg(MAX);
		vector<bool> death(MAX, 0);
		int king = 1;
		int next = 2;
		stack<int> kings;
		kings.push(king);
		int p = 1;
		while (q--) {
   			int t, v;
   			cin >> t >> v;
   			if (t == 1) {
   				edg[v].insert(next++);
   			}
   			else {
   				death[v] = true;
   				if (v != king) {
   					cout << king << "\n";
   				}
   				else {
   					while (1) {
   						while (edg[kings.top()].empty()) {
	   						kings.pop();
	   					}
	   					p = kings.top();
	   				//	cout << "FIRST FOUND: " << p << "\n";
	   					bool ok = true;
	   					while (death[p]) {
	   						if (edg[p].empty()) {
	   							ok = false;
	   							break;
	   						}
	   						int newp = *edg[kings.top()].begin();
	   						edg[p].erase(edg[p].begin());
	   						p = newp;
	   				//		cout << "NEW FOUND: " << p << "\n";
	   						kings.push(p);
	   					}
	   					if (ok) break;
   					}
   					king = p;
   					cout << king << "\n";
   				}
   			}
   			//debug(edg);
		}
	}