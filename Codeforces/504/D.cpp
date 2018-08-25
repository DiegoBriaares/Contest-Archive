#include <bits/stdc++.h>

using namespace std;

#define in first
#define fin second
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, q;
ll save;
ll a[MaxN];
bool vis[MaxN];
pair<ll, ll> rangos[MaxN];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < MaxN; i++) {
    rangos[i].in = rangos[i].fin = -1;
    vis[i] = true;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vis[a[i]] = false;
    if (rangos[a[i]].in == -1) {
      rangos[a[i]].in = i;
    }
    rangos[a[i]].fin = i;
  }
  for (int i = 1; i <= n; i++) {
    if (!a[i] && !save && vis[q]) save = i;
  }
  for (int x = q; x >= 1; x--) {
    if (!vis[x]) {
      int l = rangos[x].in, r = rangos[x].fin;
      for (int i = l; i <= r; i++) {
        if (!a[i]) {
          if (i == save) continue;
          a[i] = x;
          continue;
        }
        if (rangos[a[i]].in < l || rangos[a[i]].fin > r || a[i] < x) {
          cout << "NO\n";
          return 0;
        }
        if (vis[a[i]] && rangos[a[i]].fin > 0) i = rangos[a[i]].fin;
      }
    }
    vis[x] = true;
  }
  a[save] = q;
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j >= 1; j--) {
      if (!a[j]) a[j] = a[i];
      else break;
    }
    for (int j = i + 1; j <= n; j++) {
      if (!a[j]) a[j] = a[i];
      else break;
    }
  }
  bool ok = false;
  for (int i = 1; i <= n; i++) {
    if (a[i] == q) ok = true;
  }
  if (!ok) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

