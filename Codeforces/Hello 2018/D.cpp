#include <bits/stdc++.h>

using namespace std;

#define t first
#define a second.first
#define idx second.second

typedef long long ll;
const ll MaxN = 310002;

ll n, T;
pair<ll, pair<ll, ll> > v[MaxN];

bool solve(ll k) {
  ll sum = 0, c = k;
  for (int i = 0; i < n && c > 0; i++) {
    if (v[i].a >= k) {
      if (sum + v[i].t <= T) {
        sum += v[i].t;
        c--;
      }
    }
  }
  if (c <= 0) return true;
  return false;
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> T;
  for (int i = 0; i < n; i++) {
    cin >> v[i].a >> v[i].t;
    v[i].idx = i + 1;
  }
  sort(v, v + n);
  ll in = 0, fin = n, k = -1;
  while (in <= fin) {
    ll mid = (in + fin) / 2;
    if (solve(mid)) {
      in = mid + 1;
      k = mid;
    }
    else fin = mid - 1;
  }
  if (k == -1) {
    cout << "0\n";
    cout << "0\n";
  }
  else {
    cout << k << "\n";
    cout << k << "\n";
    ll sum = 0, c = k;
    for (int i = 0; i < n && c > 0; i++) {
      if (v[i].a >= k) {
        if (sum + v[i].t <= T) {
          sum += v[i].t;
          cout << v[i].idx << " ";
          c--;
        }
      }
    }
    cout << "\n";
  }
}
