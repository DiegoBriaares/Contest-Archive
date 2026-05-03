/**

   * author:    Diego Briaares
   * At:   01.04.2022 17:05:15
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
		while (cin >> k) {
			cin >> n;
			vector<int> a(n);
			vector<int> oc(k + 1);
			for (int i = 0; i < n; i++) {
				cin >> a[i];
				oc[a[i]]++;
			}
			set<int> vals;
			for (int i = 0; i < k; i++) {
				vals.insert(oc[i + 1]);
			}
			vector<int> v;
			copy(vals.begin(), vals.end(), back_inserter(v));
			if (n % k == 0) {
				if ((int) v.size() != 3 || v[0] + 1 != v[1] || v[1] + 1 != v[2] || v[1] != n / k) {
					cout << "*\n";
					continue;
				}
				int x, y;
				for (int i = 0; i < k; i++) {
					if (oc[i + 1] == v[0]) {
						y = i + 1;
					}
					if (oc[i + 1] == v[2]) {
						x = i + 1;
					}
				}
				cout << "-" << x << " +" << y << "\n";
				continue;
			}
			if ((n - 1) % k == 0) {
				if ((int) v.size() != 2 || v[0] + 1 != v[1]) {
					cout << "*\n";
					continue;					
				}
				int x;
				for (int i = 0; i < k; i++) {
					if (oc[i + 1] == v[1]) {
						x = i + 1;
					}
				}
				cout << "-" << x << "\n";
				continue;
			}
			if ((n + 1) % k == 0) {
				if ((int) v.size() != 2 || v[0] + 1 != v[1]) {
					cout << "*\n";
					continue;					
				}
				int x;
				for (int i = 0; i < k; i++) {
					if (oc[i + 1] == v[0]) {
						x = i + 1;
					}
				}
				cout << "+" << x << "\n";
				continue;
			}
			cout << "*\n";
		}
	}