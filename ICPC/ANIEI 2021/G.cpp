/**

   * Made by:    Diego Briaares
   * At:   23.10.2021 13:30:39
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int a,b, x, y;

	int main () {
		scanf("%d.%d.%d.%d", &a, &b, &x, &y);
		auto get = [&] (int X) {
			for (int i = 7; i >= 0; i--) {
				if (X & (1 << i)) cout << "1";
				else cout << "0";
			}
		};
		get(a);
		get(b);
		get(x);
		get(y);
		cout << "\n";
	}