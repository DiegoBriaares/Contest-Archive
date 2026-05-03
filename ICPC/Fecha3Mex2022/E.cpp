/**

   * author:    Diego Briaares
   * At:   08.10.2022 12:45:48
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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}	
		vector<int> edg(n + 1, -1);
		map<int, queue<int>> oc;
		for (int i = 0; i < n; i++) {
			if (oc.find(a[i] + 1) != oc.end() && !oc[a[i] + 1].empty()) {
				edg[oc[a[i] + 1].front()] = i;
				oc[a[i] + 1].pop();
			}
			oc[a[i]].push(i);
		}
		int arrows = 0;
		vector<bool> pop(n, false);
		for (int i = 0; i < n; i++) {
			if (!pop[i]) {
				arrows++;
				int cur = i;
				while (cur != -1) {
					pop[cur] = true;
					cur = edg[cur];
				}
			}
		}
		cout << arrows << "\n";
	}