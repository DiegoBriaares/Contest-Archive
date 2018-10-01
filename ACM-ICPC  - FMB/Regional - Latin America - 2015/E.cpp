#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 302;
const ll INF = 999999999999999;

ll c;
ll D, P, n, B;
bool vis[MaxN];
ll ans_DSP, ans_PPP;
vector<ll> edg[MaxN];
ll DSP[MaxN], PPP[MaxN];
ll memo[MaxN][10102];
bool visit[MaxN][MaxN * 10];
pair<ll, pair<ll, ll> > comp[MaxN * 10];

void dfs_1(int nodo) {
	if (vis[nodo]) return;
	vis[nodo] = true;
	if (nodo <= D) comp[c].first += DSP[nodo], comp[c].second.first++;
	else comp[c].first += PPP[nodo], comp[c].second.second++;
	for (int i = 0; i < edg[nodo].size(); i++) {
		dfs_1(edg[nodo][i]);
	}
}

void dfs_2(int nodo) {
	if (vis[nodo]) return;
	vis[nodo] = true;
	if (nodo > D) comp[c].first += PPP[nodo], comp[c].second.first++;
	else comp[c].first += DSP[nodo], comp[c].second.second++;
	for (int i = 0; i < edg[nodo].size(); i++) {
		dfs_2(edg[nodo][i]);
	}
}

ll dp(int i, int k) {
	if (k < 0) return -INF;
	if (i > c) {
		return 0;
	}
	if (visit[i][k]) return memo[i][k];
	visit[i][k] = true;
	return memo[i][k] = max(dp(i + 1, k), dp(i + 1, k - comp[i].first) + comp[i].second.second - comp[i].second.first);
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (cin >> D >> P >> n >> B) {
  	  c = 0;
  	  for (int i = 0; i < MaxN; i++) edg[i].clear();
	  memset(vis, 0, sizeof(vis));
	  memset(comp, 0, sizeof(comp));
	  memset(memo, 0, sizeof(memo));
	  memset(visit, 0, sizeof(visit));
	  for (int i = 1; i <= D; i++) {
	  	cin >> DSP[i];
	  }
	  for (int i = 1; i <= P; i++) {
	  	cin >> PPP[i + D];
	  }
	  for (int i = 0; i < n; i++) {
	  	int u, v;
	  	cin >> u >> v;
	  	v += D;
	  	edg[u].push_back(v);
	  	edg[v].push_back(u);
	  }
	  for (int i = 1; i <= P; i++) {
	  	if (!vis[i + D]) {
	  		c++;
	  		dfs_1(i + D);
		  }
	  }
	  ans_DSP = D + dp(1, B);
	  c = 0;
	  memset(vis, 0, sizeof(vis));
	  memset(comp, 0, sizeof(comp));
	  memset(memo, 0, sizeof(memo));
	  memset(visit, 0, sizeof(visit));
	  for (int i = 1; i <= D; i++) {
	  	if (!vis[i]) {
	  		c++;
	  		dfs_2(i);
		  }
	  }
	  ans_PPP = P + dp(1, B);
	  cout << ans_DSP << " " << ans_PPP << "\n";
  }
}
