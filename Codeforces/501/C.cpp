#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, m, sum, res;
vector<ll> diff;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    sum += a;
    diff.push_back(abs(a - b));
  }
  sort(all(diff));
  reverse(all(diff));
  for (int i = 0; i < n; i++) {
    if (sum <= m) {
      cout << res << "\n";
      return 0;
    }
    res++;
    sum -= diff[i];
    if (sum <= m) {
      cout << res << "\n";
      return 0;
    }
  }
  cout << "-1\n";
}
