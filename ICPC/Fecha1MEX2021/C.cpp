/**

   * Made by:    Diego Briaares
   * At:   30.09.2021 20:36:42
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

const int MAX = 1000001;

int cribe[MAX];
int primes[MAX];

	int main () {
		optimize();
		int t;
		cin >> t;
		for (int i = 2; i < MAX; i++) {
			primes[i] += primes[i - 1];
			if (!cribe[i]) {
				primes[i]++;
				for (int j = i + i; j < MAX; j += i) cribe[j] = true;
			}
		}
		while (t--) {
			int i, j;
			cin >> i >> j;
			cout << primes[j] - primes[i - 1] << "\n";		
		}
	}