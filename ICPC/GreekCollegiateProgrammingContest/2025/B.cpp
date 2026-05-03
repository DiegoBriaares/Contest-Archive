#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

  int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> ev;
    ev.push_back(make_pair(0, 0));
    for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      ev.push_back(make_pair(l, r));
    }
    ev.push_back(make_pair(t, t));
    sort(ev.begin(), ev.end());
    int mx = 0;
    int ans = 0;
    for (int i = 0; i < n + 2; i++) {
      ans = max(ans, max(0, ev[i].first - mx));
      mx = max(mx, ev[i].second);
    }

    cout << ans << "\n";

  }
