/**

   * Made by:    Diego Briaares
   * At:   13.02.2021 11:06:57
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int criba[10000001];
	int main () {
		optimize();
		int n;
		cin >> n;
		for (int i = 2; i < 10000001;) {
			if (!criba[i]) {
				for (int j = i; j < 10000001; j += i) {
					criba[j]++;
				}
			}
			if (i == 2) i++;
			else i += 2;
		}
		while (n--) {
			int a, b;
			cin >> a >> b;
			if (a == b) {
				cout << criba[a] << "\n";
				continue;
			}
			int g = __gcd(a, b);
			cout << criba[a] + criba[b] - criba[g]<< "\n";
		}
	}
