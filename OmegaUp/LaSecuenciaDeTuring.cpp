/**

   * author:    Diego Briaares
   * At:   09.11.2024 01:06:37
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
		unordered_map<int, int> indeg;
		unordered_map<int, vector<int>> edg;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			int prev = -1;
			for (int j = 0; j < k; j++) {
				int uso;
				cin >> uso;
				if (j > 0) {
					edg[prev].push_back(uso);
					indeg[uso]++;
				}
				prev = uso;
			}
		}
		set<int> S;
		for (unordered_map<int, vector<int>>::iterator it = edg.begin(); it != edg.end(); it++) {
			if (!it->second.empty()) {
				if (!indeg[it->first]) {
					S.insert(it->first);
				}
			}
		}
		while (!S.empty()) {
			int mn = *S.begin();
			S.erase(mn);
			cout << mn << " ";
			for (int i = 0; i < (int)edg[mn].size(); i++) {
				indeg[edg[mn][i]]--;
				if (!indeg[edg[mn][i]]) S.insert(edg[mn][i]);
			}
		}
		cout << "\n";
	}