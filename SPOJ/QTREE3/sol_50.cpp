#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 501002;

ll n, q;
int chN, p;
ll dad[MaxN];
bool vis[MaxN];
ll sbt_sz[MaxN];
vector<ll> bit[MaxN];
vector<ll> tree[MaxN];
vector<ll> chains[MaxN];
vector<ll> founder[MaxN];
ll heads[MaxN], chainId[MaxN], chainSz[MaxN], chainPos[MaxN], chainSt[MaxN];

ll query(int chain, int i) {
  if (i <= 0) return 0;
  ll sum = 0;
  while (i > 0) {
    sum += bit[chain][i];
    i -= (i & -i);
  }
  return sum;
}

void update(int chain, int i, int u) {
  while (i <= chainSz[chain]) {
    bit[chain][i] += u;
    i += (i & -i);
  }
}

void hld(int node) {
  if (vis[node]) return;
  vis[node] = true;
  if (heads[chN] == -1) heads[chN] = node;
  chainId[node] = chN;
  chainSz[chN]++;
  chainPos[node] = chainSz[chN];
  chains[chN].pb(0);
  founder[chN].pb(node);
  int max_subtree = 0, idx = -1;
  for (int i = 0; i < tree[node].size(); i++) {
    if (vis[tree[node][i]])continue;
    if (sbt_sz[tree[node][i]] > max_subtree) {
      max_subtree = sbt_sz[tree[node][i]];
      idx = i;
    }
  }
  if (idx != -1) {
    hld(tree[node][idx]);
  }
  for (int i = 0; i < tree[node].size(); i++) {
    if (vis[tree[node][i]])continue;
    if (i != idx) {
      chN++;
      hld(tree[node][i]);
    }
  }
}

void sizes(int node) {
  if (vis[node]) return;
  vis[node] = true;
  sbt_sz[node] = 1;
  for (int i = 0; i < tree[node].size(); i++) {
    if (vis[tree[node][i]]) continue;
    dad[tree[node][i]] = node;
    sizes(tree[node][i]);
    sbt_sz[node] += sbt_sz[tree[node][i]];
  }
}

ll get_idx(int chain, int pos) {
  ll in = 1, fin = pos, la;
  while (in <= fin) {
    ll mid = (in + fin) / 2;
    if (query(chain, mid) > 0) {
      la = mid;
      fin = mid - 1;
    }
    else in = mid + 1;
  }
  return founder[chain][la - 1];
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    tree[a].pb(b);
    tree[b].pb(a);
  }
  sizes(1);
  memset(vis, 0, sizeof(vis));
  memset(heads, -1, sizeof(heads));
  hld(1);
  for (int i = 0; i <= chN; i++) {
    bit[i].reserve(chainSz[i] + 2);
    for (int j = 0; j <= chainSz[i] + 1; j++) bit[i][j] = 0;
  }
  dad[1] = 1;
  while (q--) {
    int op, node;
    cin >> op >> node;
    if (!op) {
      int chain = chainId[node];
      int u = 1;
      if (chains[chain][chainPos[node] - 1]) {
        u *= (-1);
      }
      chains[chain][chainPos[node] - 1] = !chains[chain][chainPos[node] - 1];
      update(chain, chainPos[node], u);
    }
    else {
      ll ans = -1;
      while (node != 1) {
        int chain = chainId[node];
        ll sum = query(chain, chainPos[node]);
        if (sum > 0) {
          ans = get_idx(chain, chainPos[node]);
        }
        node = dad[heads[chain]];
      }
      cout << ans << "\n";
    }
  }
}
