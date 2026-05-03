/**

   * Made by:    Diego Briaares
   * At:   25.09.2021 13:18:18
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int t;
		cin >> t;
		while (t--) {
			long long c, r, s;
			cin >> c >> r >> s;
			int M = c / s;
			if ((c % s > 0 && r % s == 0) || ((c % s) > 0 && ((c % s) + (r % s)) > s)) M++;
			cout << M << " ";
			c -= (r * (s - 1));
			if (c <= 0) {
				cout << "0\n";
				continue;
			}
			c = max(c, 0LL);
			cout << (c + s - 1) / s << "\n";		
		}
	}