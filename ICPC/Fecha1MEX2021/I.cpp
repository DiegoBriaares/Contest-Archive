/**

   * Made by:    Diego Briaares
   * At:   02.11.2021 18:16:12
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int F(int n) {
	vector<int> dig;
	while (n > 0) {
		dig.push_back(n % 10);
		n /= 10;
	}
	int prod = 1;
	for (int i = 0; i < (int) dig.size(); i++) {
		prod *= dig[i];
	}
	return prod;
}

	int main () {
		optimize();
		int t;
		cin >> t;
		while (t--) {
			int n;
			cin >> n;
			int c = 0;
			while (n > 9) {
				n = F(n);
				c++;
			}
			cout << c << "\n";
		}
	}