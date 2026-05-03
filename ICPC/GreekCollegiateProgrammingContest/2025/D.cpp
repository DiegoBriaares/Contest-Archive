#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long b;
  cin >> n >> b;
  vector<vector<long long>> P(2, vector<long long>(n));
  for (int i = 0; i < n; i++) {
    cin >> P[0][i];
  }
  for (int i = 0; i < n; i++) {
    cin >> P[1][i];
  }

  int l = 0;
  int r = n;
  int k = -1;
  long long cost = -1;
  long long temp_cost = 0;
  auto ok = [&](int K) {
    bool can = true;
    vector<long long> costs(n);
    for (int i = 0; i < n; i++) {
      costs[i] = P[0][i] + K * P[1][i];
    }
    sort(costs.begin(), costs.end());
    long long B = b;
    for (int i = 0; i < K; i++) {
      B -= costs[i];
    }
    temp_cost = b - B;
    return B >= 0;
  };
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      k = mid;
      cost = temp_cost;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  cout << k << " " << cost << "\n";
}
