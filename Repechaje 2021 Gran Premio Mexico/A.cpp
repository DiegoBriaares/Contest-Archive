/**

   * Made by:    Diego Briaares
   * At:   13.02.2021 15:27:53
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		long long n, m;
		cin >> n >> m;
		cout << (long long)(1LL << (n)) + (long long)(1LL << (m)) - 2 << "\n";	
	}                                  