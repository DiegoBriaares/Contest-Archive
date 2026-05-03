/**

   * author:    Diego Briaares
   * At:   08.10.2022 12:23:39
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		vector<int> a(8);
		bool N = false;
		for (int i = 0; i < 8; i++) {
			cin >> a[i];
			if (a[i] == 9) {
				N = true;
			}
		}	
		if (!N) {
			cout << "S\n";
		}
		else {
			cout << "F\n";
		}
	}