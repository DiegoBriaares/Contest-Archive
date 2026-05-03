/**

   * Made by:    Diego Briaares
   * At:   17.02.2021 00:36:04
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int n, q;
		cin >> n >> q;
		map<pair<int, int>, int> edg;
		multiset<pair<int, pair<int, int>>> max_edge_count;
		vector<multiset<pair<int, int>>> mult_edge_count(n + 1);
		while (q--) {
   			char t;
   			int x, y;
   			cin >> t;
   			if (t == 'R') {
   				cin >> x >> y;
   				edg[{x, y}]++;
   				mult_edge_count[x].insert({edg[{x, y}], y});
   				max_edge_count.insert({edg[{x, y}], {x, y}});
   			}
   			else if (t == 'Q') {
   				cin >> x;
   				if (mult_edge_count[x].empty()) {
   					cout << "No info\n";
   					continue;
   				}
   				auto it = mult_edge_count[x].end();
   				it--;
   				pair<int, int> ans = *it, nuev;
   				if (it == mult_edge_count[x].begin()) {
   					cout << ans.second << "\n";
   					continue;
   				}
   				it--;
   				nuev = *it;
   				if (ans.first == nuev.first) {
   					cout << "Multiple\n";
   					continue;
   				}
   				cout << ans.second << "\n";
   			}
   			else {
   				if (max_edge_count.empty()) {
   					cout << "No info\n";
   					continue;
   				}
   				auto it = max_edge_count.end();
   				it--;
   				pair<int, pair<int, int>> ans = *it, nuev;
   				if (it == max_edge_count.begin()) {
   					cout << ans.second.first << " " << ans.second.second << "\n";
   					continue;
   				}
   				it--;
   				nuev = *it;
   				if (ans.first == nuev.first) {
   					cout << "Multiple\n";
   					continue;
   				}
   				cout << ans.second.first << " " << ans.second.second << "\n";
   			}
		}
	}