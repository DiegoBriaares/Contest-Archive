/**

   * Made by:    Diego Briaares
   * At:   23.10.2021 13:40:15
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		string s;
		while (cin >> s) {
			int n = (int) s.size();
   			int q;
   			cin >> q;
   			while (q--) {
   				int X, Y;
   				cin >> X >> Y;
   				X--, Y--;
   				Y = (Y + X) % n;
   				cout << s[Y] << "\n"; 
   			}
		}
	}