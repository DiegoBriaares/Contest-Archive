#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

struct Tree_node {
  vector<ll> arr;
};

ll n, q;
ll l, r, k;
ll a[MaxN];

vector<ll> to_map;
map<ll, ll> keys, resp_keys;

Tree_node ST[4 * MaxN];

vector<ll> merge_segments (vector<ll> x, vector<ll> y) {
  vector<ll> result;
  int i_x = 0, i_y = 0;
  while (i_x < x.size() && i_y < y.size()) {
    if (x[i_x] < y[i_y]) {
      result.push_back(x[i_x]);
      i_x++;
    }
    else {
      result.push_back(y[i_y]);
      i_y++;
    }
  }
  while (i_x < x.size()) {
    result.push_back(x[i_x]);
    i_x++;
  }
  while (i_y < y.size()) {
    result.push_back(y[i_y]);
    i_y++;
  }
  return result;
}

void build(int in, int fin, int nodo) {
  if (in == fin) {
    ST[nodo].arr.push_back(a[in]);
    return;
  }
  int mid = (in + fin) / 2;
  int left = (nodo * 2) + 1;
  int right = (nodo * 2) + 2;
  build(in, mid, left);
  build(mid + 1, fin, right);
  ST[nodo].arr = merge_segments(ST[left].arr, ST[right].arr);
}

ll query(int in, int fin, int nodo, ll key) {
  if (in > r || fin < l) return 0;
  if (l <= in && fin <= r) {
    ll c = (upper_bound(all(ST[nodo].arr), key) - ST[nodo].arr.begin());
    c = max(c, 0LL);
    return c;
  }
  int mid = (in + fin) / 2;
  int left = (nodo * 2) + 1;
  int right = (nodo * 2) + 2;
  return query(in, mid, left, key) + query(mid + 1, fin, right, key);
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    to_map.push_back(a[i]);
  }
  sort(all(to_map));
  int p = 1;
  for (int i = 0; i < n; i++) {
    if (i && to_map[i] != to_map[i - 1]) p++;
    keys[to_map[i]] = p;
    resp_keys[p] = to_map[i];
  }
  for (int i = 0; i < n; i++) {
    a[i] = keys[a[i]];
  }
  build(0, n - 1, 0);
  while (q--) {
    cin >> l >> r >> k;
    l--, r--;
    ll in = 1, fin = n, la = -1;
    while (in <= fin) {
      int mid = (in + fin) / 2;
      ll count = query(0, n - 1, 0, mid);
      if (count >= k) {
        fin = mid - 1;
        if (count == k) la = mid;
      }
      else {
        in = mid + 1;
      }
    }
    cout << resp_keys[la] << "\n";
  }
}
