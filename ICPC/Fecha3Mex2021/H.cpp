/**

   * Made by:    Diego Briaares
   * At:   30.10.2021 13:04:09
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int n, k;
		cin >> n >> k;
		vector<multiset<int>> M(k + 1);
		vector<int> col(n), s(n), res(n);
		for (int i = 0; i < n; i++)	{
			int a, b;
			cin >> a >> b;
			M[b].insert(a);
			col[i] = b;
			s[i] = a;
		}
		sort(s.begin(), s.end());
		for (int i = 0; i < n; i++) {
			res[i] = *M[col[i]].begin();
			M[col[i]].erase(M[col[i]].begin());
		}
		if (s != res) cout << "N\n";
		else cout << "Y\n";
	}