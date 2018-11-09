#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, q;
int chN, p;
bool vis[MaxN];
ll sbt_sz[MaxN];
vector<ll> ST[MaxN];
vector<ll> tree[MaxN];
vector<ll> chains[MaxN];
ll heads[MaxN], chainId[MaxN], chainSz[MaxN], chainPos[MaxN], chainSt[MaxN];

void hld(int node) {
  if (vis[node]) return;
  vis[node] = true;
  if (heads[chN] == -1) heads[chN] = node;
  chainId[node] = chN;
  chainPos[node] = chainSz[chN];
  chainSz[chN]++;
  chains[chN].pb(node);
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
    sizes(tree[node][i]);
    sbt_sz[node] += sbt_sz[tree[node][i]];
  }
}

void update(int in, int fin, int node, int chain, int pos) {
  if (in > pos || fin < pos) return;
  if (in == pos && pos == fin) {
    ST[chain][node] = !ST[chain][node];
    return;
  }
  int mid = (in + fin) / 2LL;
  int left = (node * 2) + 1;
  int right = (node * 2) + 2;
  update(in, mid, left, chain, pos);
  update(mid + 1, fin, right, chain, pos);
  ST[chain][node] = ST[chain][left] + ST[chain][right];
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
    ST[i].reserve(chainSz[i] + 1);
  }
  while (q--) {
    int op, node;
    cin >> op >> node;
    if (!op) {
      update(0, chainSz[node] - 1, 0, chainId[node], chainPos[node]);
    }
    else {
      cout << query(0, chainSz[node] - 1, 0, chainId[node], chainPos[node]);
    }
  }
}
