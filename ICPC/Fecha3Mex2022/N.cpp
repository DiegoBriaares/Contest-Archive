/**

   * author:    Diego Briaares
   * At:   08.10.2022 16:01:20
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

	int main () {
		optimize();
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<long long> b(n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}	
		long long k, l;
		cin >> k >> l;
		ordered_set<pair<long long, long long>> S;
		long long uno = 0;
		for (int i = 0; i < k; i++) {
		  int idx = n - i - 1;
			uno += a[idx];
			S.insert(make_pair(b[idx], idx));
		}
		long long dos = 0;
		for (int i = 0; i < l; i++) {
			auto it = *S.find_by_order(k - i - 1);
			dos += it.first;
		}
		long long score = uno + dos;
		for (int i = 0; i < k; i++) {
			uno += a[i];
			int idx = n - k + i;
			uno -= a[idx];
			int p = S.order_of_key(make_pair(b[idx], idx));
			if (p >= k - l) {
				dos -= b[idx];
				auto it = *S.find_by_order(k - l - 1);
				dos += it.first;
			}
			S.erase(make_pair(b[idx], idx));
			S.insert(make_pair(b[i], i));
			int newp = S.order_of_key(make_pair(b[i], i));
			if (newp >= k - l) {
				auto it = *S.find_by_order(k - l - 1);
				dos -= it.first;
				dos += b[i];
			}
			score = max(score, uno + dos);
		}
		cout << score << "\n";
	}