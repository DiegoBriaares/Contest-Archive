/**

   * author:    Diego Briaares
   * At:   08.10.2022 14:52:26
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int n, x, y;
		cin >> n;
		cin >> x >> y;
		auto calc = [&] (int X) {
			int f = 0;
			for (int i = 0; i < n; i++) {
				if (X & (1 << i)) {
					f = i;
					break;
				}
			}
			return (n - 1) - f;
		};
		cout << min(calc(x), calc(y)) << "\n";
	}
