#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, m, k;
ll a[MaxN];
ll deg[MaxN];
ll ans[MaxN];
set<pair<ll, ll> > S;
pair<ll, ll> op[MaxN];
vector<ll> tree[MaxN];

void leave_grade_k() {
  while (!S.empty()) {
    set<pair<ll, ll> >::iterator it = S.begin();
    pair<ll, ll> mi = *it;
    if (mi.first < k) {
      S.erase(it);
      for (int j = 0; j < tree[mi.second].size(); j++) {
        pair<ll, ll> aux = mp(deg[tree[mi.second][j]], tree[mi.second][j]);
        if (S.find(aux) != S.end()) {
          S.erase(aux);
          deg[tree[mi.second][j]]--;
          aux.first--;
          S.insert(aux);
        }
      }
    }
    else {
      break;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> op[i].first >> op[i].second;
    a = op[i].first;
    b = op[i].second;
    tree[a].pb(b);
    tree[b].pb(a);
  }
  for (int i = 1; i <= n; i++) {
    deg[i] = tree[i].size();
    sort(all(tree[i]));
    S.insert(mp(deg[i], i));
  }
  leave_grade_k();
  for (int i = m; i > 0; i--) {
    ans[i] = S.size();
    pair<ll, ll> a = mp(deg[op[i].first], op[i].first), b = mp(deg[op[i].second], op[i].second);
    if (S.find(a) != S.end() && S.find(b) != S.end()) {
      S.erase(a);
      S.erase(b);
      deg[op[i].first]--;
      deg[op[i].second]--;
      a.first--;
      b.first--;
      S.insert(a);
      S.insert(b);
      tree[op[i].first].erase(lower_bound(all(tree[op[i].first]), op[i].second));
      tree[op[i].second].erase(lower_bound(all(tree[op[i].second]), op[i].first));
      leave_grade_k();
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << "\n";
  }
}
