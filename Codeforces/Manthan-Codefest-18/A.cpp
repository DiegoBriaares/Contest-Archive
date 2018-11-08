#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 1010000002;

ll n;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  ll p = 1LL, ans = 1;
  while (p * 2LL <= n) {
    p *= 2LL;
    ans++;
  }
  cout << ans << "\n";
}
