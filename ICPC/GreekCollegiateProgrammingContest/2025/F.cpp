#include <iostream>
#include <vector>
#include <utility>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds; 
using namespace std;
  
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, Q;
  cin >> n >> Q;
  int L1, L2;
  cin >> L1 >> L2;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  vector<vector<pair<pair<int, int>, int>>> R(2);
  for (int i = 0; i < Q; i++) {
    int t, idx, k;
    cin >> t >> idx >> k;
    t--, idx--, k--;
    R[t].push_back(make_pair(make_pair(idx, k), i));
  }
  sort(R[0].begin(), R[0].end());
  sort(R[1].begin(), R[1].end());

  ordered_set<pair<int, int>> S;
  vector<pair<pair<int, int>, int>> ans(Q);

  for (int i = 0; i < L1; i++) {
    S.insert(make_pair(a[i], i));
  }
  int l = 0;
  int r = L1 - 1;
  for (int i = 0; i < (int)R[0].size(); i++) {
    int idx = R[0][i].first.first;
    int k = R[0][i].first.second;
    while (l < idx) {
      S.erase(make_pair(a[l], l));
      l++;
      r++;
      S.insert(make_pair(a[r], r));
    }
    assert(l == idx);
    ans[R[0][i].second] = make_pair(make_pair((*S.find_by_order(0)).first, (*S.find_by_order(k)).first), (*S.find_by_order(L1 - 1)).first);
  }
  S.clear();
  for (int i = 0; i < L2; i++) {
    S.insert(make_pair(a[i], i));
  }
  l = 0;
  r = L2 - 1;
  for (int i = 0; i < (int)R[1].size(); i++) {
    int idx = R[1][i].first.first;
    int k = R[1][i].first.second;
    while (l < idx) {
      S.erase(make_pair(a[l], l));
      l++;
      r++;
      S.insert(make_pair(a[r], r));
    }
    assert(l == idx);
    ans[R[1][i].second] = make_pair(make_pair((*S.find_by_order(0)).first, (*S.find_by_order(k)).first), (*S.find_by_order(L2 - 1)).first);
  }

  for (int i = 0; i < Q; i++) {
    auto e = ans[i];
    cout << e.first.first << " " << e.first.second << " " << e.second << "\n";
  }
}
