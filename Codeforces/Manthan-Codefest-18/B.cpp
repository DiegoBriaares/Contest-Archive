#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll ans;
ll n, s;
ll a[MaxN];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int mid = (n / 2);
  if (a[mid] < s) {
    ans = s - a[mid];
    a[mid] = s;
    for (int i = mid + 1; i < n; i++) {
      if (a[i] < a[i - 1]) {
        ans += a[i - 1] - a[i];
        a[i] = a[i - 1];
      }
    }
  }
  else {
    ans = a[mid] - s;
    a[mid] = s;
    for (int i = mid - 1; i >= 0; i--) {
      if (a[i] > a[i + 1]) {
        ans += a[i] - a[i + 1];
        a[i] = a[i + 1];
      }
    }
  }
  cout << ans << "\n";
}
