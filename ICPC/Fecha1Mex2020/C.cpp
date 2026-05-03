/**

   * Made by:    Diego Briaares
   * At:   17.02.2021 00:01:02
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

map<string, int> ids;
int parent[300001];
string les[300001];

int par(int x) {
	if (parent[x] == x) return x;
	return par(parent[x]);
}

void join (int a, int b, string m) {
	int p;
	a = par(a), b = par(b);
	if (les[a].empty() && les[b].empty()) {
		parent[a] = b;
		p = b;
	}
	else if (les[a].empty()) {
		parent[a] = b;
		p = b;
	}
	else if (les[b].empty()) {
		parent[b] = a;
		p = a;
	}
	else {
		if (les[a].size() < les[b].size()) {
			parent[b] = a;
			p = a;
		}
		else if (les[a].size() > les[b].size()) {
			parent[a] = b;
			p = b;
		}
		else {
			if (les[a] <= les[b]) {
				parent[b] = a;
				p = a;
			}
			else {
				parent[a] = b;
				p = b;
			}
		}
	}
	if (les[p].empty() || les[p].size() > m.size()) les[p] = m;
	else if (les[p].size() == m.size()) les[p] = min(les[p], m);
}

	int main () {
	//	optimize();
		int n;
		cin >> n;
		vector<pair<string, string>> edg;
		for (int i = 0; i < n; i++)	 {
			string u, v;
			cin >> u >> v;
			edg.push_back({u, v});
		}
		for (int i = 1; i < 300001; i++) {
			parent[i] = i;
		}
		int id = 1;
		for (int i = 0; i < n; i++)	 {
		    if (ids.find(edg[i].first) == ids.end()) {
		    	ids[edg[i].first] = id++;
		    }
		    if (ids.find(edg[i].second) == ids.end()) {
		    	ids[edg[i].second] = id++;
		    }
		    string m;
		    if (edg[i].first.size() < edg[i].second.size()) {
		    	m = edg[i].first;
		    }
		    else if (edg[i].first.size() > edg[i].second.size()) {
		    	m = edg[i].second;
		    }
		    else {
		    	m = min(edg[i].first, edg[i].second);
		    }
		    join(ids[edg[i].first], ids[edg[i].second], m);
		}
		string s;
		while (cin >> s) {
			if (ids.find(s) == ids.end()) {
				cout << s << " ";
			}
			else {
				int p = par(ids[s]);
				cout << les[p] << " ";
			}
		}
		cout << "\n";
	}