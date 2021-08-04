/**

   * Made by:    Diego Briaares
   * At:   03.08.2021 23:25:40
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
		char st = 'B';
		for (int i = 0; i < n; i++)	 {
			char a;
			cin >> a;
			if (a == st) {
				if (a == 'A') {
					st++;
					cout << "R\n";
				}
				else {
					st--;
					cout << "L\n";
				}
			}
			else cout << "M\n";
		}
	}