/**

   * author:    Diego Briaares
   * At:   03.04.2022 14:37:01
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
		vector<pair<long long, long long>> a(n);
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;
			sum += a[i].first;
		}
		vector<bool> used(n, false);
		vector<int> order(n);
		for (int i = n - 1; i >= 0; i--) {
			int id = -1;
			for (int j = 0; j < n; j++) {
				if (used[j]) continue;
				if (a[j].second < sum) continue;
				if (id == -1 || a[j].second >= a[id].second) {
				  id = j;
				}
			}
			if (id == -1) {
				cout << "*\n";
				return 0;
			}
			order[i] = id;
			used[id] = true;
			sum -= a[id].first;
		}
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[order[i]].first;			
			int min_id = n, p = i;
			long long min_diff = a[order[i]].second - sum;
			long long temp_sum = 0;
			for (int j = i + 1; j < n; j++) {
				if (order[j] > order[i] || min_diff < a[order[j]].first) {
					temp_sum += a[order[j]].first;							
					min_diff = min(min_diff, a[order[j]].second - sum - temp_sum);
					continue;
				}
				if (min_id > order[j]) {
					min_id = order[j];
					p = j;
				}
				temp_sum += a[order[j]].first;
				min_diff = min(min_diff, a[order[j]].second - sum - temp_sum);
			}
			if (p != i) {
				vector<int> new_order = order;
				for (int j = p; j > i; j--) {
					new_order[j] = order[j - 1];
				}
				new_order[i] = order[p];
				sum -= a[order[i]].first;
				sum += a[order[p]].first;
				order = new_order;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << order[i] + 1 << " ";
		}
		cout << "\n";
	}