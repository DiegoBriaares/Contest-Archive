#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n;
ll p;
ll path[MaxN];
bool vis[MaxN];
set<ll> tree[MaxN];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    tree[a].insert(b);
    tree[b].insert(a);
  }
  for (int i = 1; i <= n; i++) {
    cin >> path[i];
  }
  if (path[1] != 1) {
    cout << "No\n";
    return 0;
  }
  p = 2;
  queue<ll> cola;
  cola.push(1);
  while (!cola.empty()) {
    int st = cola.front();
    cola.pop();
    for (int i = 0; i < tree[st].size() - (st != 1 ? 1 : 0); i++) {
      if (tree[st].find(path[p]) != tree[st].end()) {
        cola.push(path[p++]);
      }
      else {
        cout << "No\n";
        return 0;
      }
    }
  }
  if (p < n) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
}
