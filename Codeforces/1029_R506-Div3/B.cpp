#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n;
ll a[MaxN];
ll resp, cont;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  resp = 1;
  cont = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] <= a[i - 1] * 2LL) {
      cont++;
    }
    else {
      cont = 1;
    }
    resp = max(resp, cont);
  }
  cout << resp << "\n";
}

