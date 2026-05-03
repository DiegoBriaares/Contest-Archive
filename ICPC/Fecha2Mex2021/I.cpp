/**

   * Made by:    Diego Briaares
   * At:   25.09.2021 13:09:51
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
			long long n;
			cin >> n;
			int c = 0;
			while (n > 9) {
				long long x = n, p = 1;
				while (x > 0) {
					p *= ((x % 10));
					x /= 10;
				}
				n = p;
				c++;
			}
			cout << c << "\n";
		}
	}