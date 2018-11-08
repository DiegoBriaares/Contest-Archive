#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, ans;
string a, b;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> a >> b;
  for (int i = 1; i < n; i++) {
    if (a[i] != b[i] && a[i - 1] != b[i - 1] && a[i - 1] == b[i] && a[i] == b[i - 1]) {
      a[i] = b[i];
      a[i - 1] = b[i - 1];
      ans++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      ans++;
    }
  }
  cout << ans << "\n";
}
