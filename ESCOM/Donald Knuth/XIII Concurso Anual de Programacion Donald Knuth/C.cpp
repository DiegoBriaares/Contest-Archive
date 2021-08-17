/**

   * Made by:    Diego Briaares
   * At:   13.08.2021 15:36:53
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
		vector<int> a(n);
		int suit = 0;
		for (int i = 0; i < n; i++)	{
			cin >> a[i];
			if (a[i] == i + 1) suit++;
		}
		cout << suit << "\n";
	}