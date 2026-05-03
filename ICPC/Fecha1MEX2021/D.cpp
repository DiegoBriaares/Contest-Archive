/**

   * author:    Diego Briaares
   * At:   14.05.2022 14:44:24
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

	int main () {
		optimize();
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> M(n. vector<int>(n));
		for (int i = 0; i < m; i++)	{
			int u, v;
			cin >> u >> v;
			M[u][v]++;
		}
		
	}