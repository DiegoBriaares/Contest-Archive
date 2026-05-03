/**

   * Made by:    Diego Briaares
   * At:   23.10.2021 13:20:12
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int a, b, x, y, c;

	int main () {
		int t;
		cin >> t;
		while (t--) {
			c = 0;
			scanf("%d:%d", &a, &b);
			scanf("%d:%d", &x, &y);
			while (a != x) {
				a = (a + 1) % 24;
				b = (b + 1) % 60;
				c++;
			}
			while (b != y) {
				b = (b + 1) % 60;
				c++;
			}
			cout << c << "\n";
		}
	}