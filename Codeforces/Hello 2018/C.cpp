#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MaxN = 310002;
const ll MaxLog = 31;
const ll INF = 1000000000000000000;

ll n, L, cost, ans;
ll c[MaxN], minCost[MaxN];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> L;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  minCost[0] = c[0];
  for (int i = 1; i < MaxLog; i++) {
    if (i < n) {
      minCost[i] = min(c[i], minCost[i - 1] * 2LL);
    }
    else {
      minCost[i] = minCost[i - 1] * 2LL;
    }
  }
  ll d = 0;
  ans = INF;
  for (int i = 0; i < MaxLog; i++) {
    if ((L & (1LL << i))) {
      d = i;
    }
  }
  for (int i = MaxLog - 1; i >= 0; i--) {
    if ((L & (1LL << i))) {
      cost += minCost[i];
    }
    else {
      ans = min(ans, minCost[i] + cost);
    }
  }
  ans = min(ans, cost);
  cout << ans << "\n";
}
