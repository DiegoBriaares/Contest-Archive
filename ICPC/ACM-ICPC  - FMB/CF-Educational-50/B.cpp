#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll q;
  cin >> q;
  while (q--) {
    ll x, y, k;
    cin >> x >> y >> k;
    if (max(abs(x), abs(y)) > k) cout << "-1\n";
    else {
        cout << k - ((k - x) % 2LL + (k - y) % 2LL) << "\n";
    }
  }
}
