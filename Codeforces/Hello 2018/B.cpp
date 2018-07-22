#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MaxN = 310002;

ll n;
bool ok;
bool memo[MaxN];
vector<ll> edg[MaxN];

void dfs (int nodo) {
  if (memo[nodo]) return;
  memo[nodo] = true;
  int nl = 0;
  for (int i = 0; i < edg[nodo].size(); i++) {
    int son = edg[nodo][i];
    if (edg[son].size() == 0) nl++;
    dfs(son);
  }
  if (edg[nodo].size() > 0 && nl < 3) ok = false;
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    ll dad;
    cin >> dad;
    edg[dad].push_back(i);
  }
  ok = true;
  dfs(1);
  if (ok) cout << "Yes\n";
  else cout << "No\n";
}
