/**

   * Made by:    Diego Briaares
   * At:   12.08.2021 13:16:00
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int words;
		cin >> words;
		while (words--) {
	   		string w;
   			cin >> w;
   			if (w.size() > 10) {
   				cout << w[0] << (int)w.size() - 2 << w.back() << "\n";
   			}
   			else cout << w << "\n";
		}
	}