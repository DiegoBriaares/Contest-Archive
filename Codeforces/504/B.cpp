#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, k;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  ll resp = (k / 2LL) - (k % 2 == 0);
  if (resp > n) {
    cout << "0\n";
  }
  else {
    if (n < k) {
      resp = min(resp, (n - (resp + (k % 2 == 0))));
      resp = max(resp, 0LL);
      cout << resp << "\n";
    }
    else {
      resp = max(resp, 0LL);
      cout << resp << "\n";
    }
  }
}

