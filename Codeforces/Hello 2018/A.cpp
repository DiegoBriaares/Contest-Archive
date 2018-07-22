#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MaxN = 310002;

ll n, m;
ll v[MaxN];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  ll pot = 1;
  while (n > 0 && pot < m) {
    pot *= 2LL;
    n--;
  }
  if (n) {
    cout << m << "\n";
  }
  else {
    cout << (m - (m / pot) * pot) << "\n";
  }
}
