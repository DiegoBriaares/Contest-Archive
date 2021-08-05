/**

   * Made by:    Diego Briaares
   * At:   16.02.2021 21:43:25
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		vector<int> h(19);
		for (int i = 0; i < 18; i++) {
			cin >> h[i];
		}
		string p, c;
		int ans = 0;
		for (int i = 0; i < 18; i++) {
			cin >> p;
			if (p[0] == 'h') {
				ans++;
				cin >> c;
				cin >> c;
			}
			if (p[0] == 'c') ans += h[i] - 4;
			if (p[0] == 'a') ans += h[i] - 3;
			if (p[0] == 'e') ans += h[i] - 2;
			if (p[0] == 'b' && p[1] == 'i') ans += h[i] - 1;
			if (p[0] == 'p') ans += h[i];
			if (p[0] == 'b' && p[1] == 'o') ans += h[i] + 1;
			if (p[0] == 'd') {
				ans += h[i] + 2;
				cin >> c;
			}
			if (p[0] == 't') {
				ans += h[i] + 3;
				cin >> c;
			}
		}
		cout << ans << "\n";  
	}