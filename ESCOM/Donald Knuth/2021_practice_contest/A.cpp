/**

   * Made by:    Diego Briaares
   * At:   12.08.2021 13:07:11
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
		if (n & 1 || n == 2) cout << "NO\n";
		else cout << "YES\n";	
	}