/**
 
   * author:    Diego Briaares
   * At:   11.11.2024 22:08:38
**/
 
#include <bits/stdc++.h>
using namespace std;
 
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}
 
	int main () {
		optimize();
		int n;
		cin >> n;
		vector<int> a(n + 1);
		vector<int> app(n + 2, 0);
		for (int i = 1; i <= n; i++)	{
			cin >> a[i];
			if (a[i]) {
				app[a[i]] = i;
			}
		}
		int i, K, L, R;
		i = 1;
		K = 0;
		L = 1;
		R = n;
		auto incr = [&]() {
			K++;
			while (app[K]) {
				K++;
			}
		};
		incr();
		while (i <= n) {
			if (!app[i]) {
				i++;
			}
			else {
				while (L < app[i] && a[L] != 0 && a[L] < K) L++;
				while (R > app[i] && a[R] != 0 && a[R] < K) R--;
				if (R - app[i] < app[i] - L) {
					while (R > app[i]) {
						if (K >= i) {
							break;
						}												
						if (!a[R]) {
							a[R--] = K;
							incr();
						}
						else {
							R--;
						}
					}
					while (L < app[i]) {
						if (K >= i) {
							break;
						}												
						if (!a[L]) {
							a[L++] = K;
							incr();
						}
						else {
							L++;
						}
					}
				}
				else {
					while (L < app[i]) {
						if (K >= i) {
							break;
						}												
						if (!a[L]) {
							a[L++] = K;
							incr();
						}
						else {
							L++;
						}
					}
					while (R > app[i]) {
						if (K >= i) {
							break;
						}												
						if (!a[R]) {
							a[R--] = K;
							incr();
						}
						else {
							R--;
						}
					}										
				}
				i++;
			}
		}
		for (L = 1; L <= n; L++) {
			if (!a[L]) {
				a[L] = K++;
			}
		}
		bool ok = true;
		bool inc = true;
		for (L = 2; L <= n; L++) {
			if (inc) {
				if (a[L] < a[L - 1]) {
					inc = false;
				}
			}
			else {
				if (a[L] > a[L - 1]) {
					ok = false;
				}
			}
		}
		if (!ok) {
			cout << "*\n";
		}
		else {
			for (L = 1; L <= n; L++) {
				cout << a[L] << " ";
			}
			cout << "\n";
		}
	}