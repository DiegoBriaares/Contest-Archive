/**

   * Made by:    Diego Briaares
   * At:   02.08.2021 14:34:10
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int Q;
		cin >> Q;
		map<string, bool> A;
		while (Q--) {
   			string a, b, c;
   			cin >> a >> b >> c;
   			if (b == "createview") {
   				if (A.find(c) != A.end()) {
   					cout << "La vista " << c << " ya existe\n";
   				}
   				else A[c] = true;
   			}
   			else {
   				if (A.find(c) != A.end()) {
   					cout << "Vista " << c << " en uso\n";
   				}
   				else {
   					cout << "La vista " << c << " no ha sido creada\n";
   				}
   			}
		}
	}