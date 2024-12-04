/**

   * author:    Diego Briaares
   * At:   03.12.2024 20:24:23
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

  int main () {
    optimize();
    int t;
    cin >> t;
    while (t--) {
			int n;
			cin >> n;
			int mb, comp;
			mb = comp = 0;
			for (int i = 0; i < 20; i++) {
				if ((n & (1 << i))) {
					mb = i;
				}
				else {
					if ((1 << i) < n) {
						comp |= (1 << i);
					}
				}
			}
			int r;
			vector<int> ans;
			if ((n + 2) == (1 << (mb + 1))) {
				ans.push_back(n);
				ans.push_back(3);
				ans.push_back(1);
				r = n | comp;				
			}
			else if (n & 1) {
				ans.push_back(n);
				ans.push_back(n - 1);
				ans.push_back(1);
				ans.push_back(3);
				r = n;
			}
			else {
				ans.push_back(n);
				ans.push_back(comp);
				ans.push_back(comp - 1);
				int x, y;
				if (comp == 1 || comp == 3) {
					x = n - 1;
					y = n - 3;
				}
				else {
					x = 1;
					y = 3;
				}
				ans.push_back(x);
				ans.push_back(y);
				r = n | comp;
			}
			vector<bool> is(n + 1, false);
			for (auto e : ans) {
				is[e] = true;
			}
			for (int i = 1; i <= n; i++) {
				if (!is[i]) {
					ans.push_back(i);
					is[i] = true;
				}
			}
			cout << r << "\n";
			reverse(ans.begin(), ans.end());
			for (auto e : ans) {
				cout << e << " ";
			}
			cout << "\n";
		}
  }
