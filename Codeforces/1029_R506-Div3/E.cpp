#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, resp;
bool vis[MaxN];
vector<ll> edg[MaxN];
vector<ll> DisfNodes;

bool cmp(ll a, ll b) {
  return edg[a].size() < edg[b].size();
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    edg[u].push_back(v);
    edg[v].push_back(u);
  }
  for (int i = 2; i <= n; i++) {
    bool ConnRoot = false;
    for (int it = 0; it < edg[i].size(); it++) {
      if (ConnRoot) break;
      if (edg[i][it] == 1) {
        ConnRoot = true;
        break;
      }
      for (int j = 0; j < edg[edg[i][it]].size(); j++) {
       if (edg[edg[i][it]][j] == 1) {
        ConnRoot = true;
        break;
        }
      }
    }
    if (!ConnRoot) DisfNodes.push_back(i);
  }
  vis[1] = true;
  for (int i = 2; i <= n; i++) {
    for (int it = 0; it < edg[i].size(); it++) {
      if (edg[i][it] == 1) {
        vis[i] = true;
        break;
      }
    }
  }
  sort(all(DisfNodes), cmp);
  for (int i = 0; i < DisfNodes.size(); i++) {
    ll nodo = DisfNodes[i];
    if (!vis[nodo]) {
      ll adyNode = nodo, maxGrade = edg[nodo].size();
      bool allOk = false;
      for (int it = 0; it < edg[nodo].size(); it++) {
        if (vis[edg[nodo][it]]) {
          allOk = true;
          break;
        }
        if (edg[edg[nodo][it]].size() >= maxGrade) {
          maxGrade = edg[edg[nodo][it]].size();
          adyNode = edg[nodo][it];
        }
      }
      if (allOk) continue;
      vis[adyNode] = true;
      resp++;
    }
  }
  cout << resp << "\n";
}

