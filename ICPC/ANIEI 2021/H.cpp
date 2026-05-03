/**

   * Made by:    Diego Briaares
   * At:   23.10.2021 13:04:00
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
		priority_queue<pair<long long, pair<int, string>>> pq;
		int it = 1000000;
		while (cin >> s) {
			it--;
   			if (s != "V") {
   				long long x;
   				cin >> x;
   				pq.push({x, {it, s}});
   			}
   			else {
   				if (!pq.empty()) {
   					auto x = pq.top();
   					pq.pop();
   					cout << x.second.second;
   				}
   				cout <<"\n";
   			}
		}
	}