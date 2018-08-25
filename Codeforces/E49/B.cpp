#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, q;

ll up(ll a, ll b) {
  if (a % b != 0) return (a / b) + 1;
  return (a / b);
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  while (q--) {
    ll x, y;
    cin >> x >> y;
    ll resp = 0;
    if ((x + y) % 2 == 0) {
      if (x & 1) {
        resp += (x / 2LL) * up(n , 2LL); 
        resp += (x / 2LL) * (n / 2LL);
        resp += up(y, 2LL);
      }
      else {
        resp += (x / 2LL) * up(n , 2LL); 
        resp += ((x / 2LL) - 1) * (n / 2LL);
        resp += y / 2LL;
      }
    }
    else {
      resp = up(n * n, 2LL);
      if (x & 1) {
        resp += (x / 2LL) * (n / 2LL); 
        resp += (x / 2LL) * up(n, 2LL);
        resp += y / 2LL;
      }
      else {
        resp += (x / 2LL) * (n / 2LL); 
        resp += ((x / 2LL) - 1) * up(n , 2LL);
        resp += up(y, 2LL);
      }
    }
    cout << resp << "\n";
  }
}

