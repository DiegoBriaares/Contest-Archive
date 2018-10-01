#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;
const ll INF = 999999999999999;

ll n, m;
ll E[MaxN];
ll dp[MaxN];
ll acum[MaxN];
vector<ll> A_2;
vector<pair<ll, ll> > A;
map<pair<ll, ll>, ll> mapa;
pair<ll, pair<ll, ll> > shops[MaxN];

vector<pair<ll, ll> > level_shops[MaxN];

ll ST[MaxN];

void build(int in, int fin, int nodo) {
	if (in == fin) {
		ST[nodo] = INF;
		return;
	}
	int mid = (in + fin) / 2;
	int left = nodo * 2 + 1;
	int right = nodo *2 + 2;
	build(in, mid, left);
	build(mid + 1, fin, right);
	ST[nodo] = min(ST[left], ST[right]);
}

ll query(int in, int fin, int nodo, int l, int r) {
	if (in > r || fin < l) return INF;
	if (l <= in && fin <= r) return ST[nodo];
	int mid = (in + fin) / 2;
	int left = nodo * 2 + 1;
	int right = nodo *2 + 2;
	return min(query(in, mid, left, l, r), query(mid + 1, fin, right, l, r));
}

void update(int in, int fin, int nodo, int l, int r, int val) {
	if (in > r || fin < l) return;
	if (l <= in && fin <= r) {
		ST[nodo] = val;
		return;
	}
	int mid = (in + fin) / 2;
	int left = nodo * 2 + 1;
	int right = nodo *2 + 2;
	update(in, mid, left, l, r, val);
	update(mid + 1, fin, right, l, r, val);
	ST[nodo] = min(ST[left], ST[right]);
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (cin >> n >> m) {
  	memset(dp, 0, sizeof(dp));
  	memset(acum, 0, sizeof(acum));
  	memset(ST, 0, sizeof(ST));
  	memset(shops, 0, sizeof(shops));
  	A.clear();
  	A_2.clear();
  	mapa.clear();
  	for (int i = 0; i < MaxN; i++) level_shops[i].clear();
	  for (int i = 1; i <= n; i++) {
	    cin >> E[i];
	    acum[i] = acum[i - 1] + E[i];
	  }
	  for (int i = 1; i <= m; i++) {
	  	cin >> shops[i].first >> shops[i].second.first >> shops[i].second.second;
	  	level_shops[shops[i].first].push_back(mp(shops[i].second.first, i));
	  	A.push_back(mp(shops[i].second.first + acum[shops[i].first - 1], i));
	  }
	  sort(all(A));
	  for (int i = 0; i < m; i++) {
	  	mapa[A[i]] = i;
	  	A_2.push_back(A[i].first);
	  }
	  build(0, m - 1, 0);
	  for (int j = 0; j < level_shops[1].size(); j++) {
	  	update(0, m - 1, 0, mapa[mp(level_shops[1][j].first, level_shops[1][j].second)], mapa[mp(level_shops[1][j].first, level_shops[1][j].second)], shops[level_shops[1][j].second].second.second);
	  }
	  bool corta = false;
	  for (int i = 2; i <= n; i++) {
	  	if (A_2[A_2.size() - 1] < acum[i]) {
	  		corta = true;
	  		break;
		  }
	  	int idx = (lower_bound(all(A_2), acum[i]) - A_2.begin());
	  	dp[i] = query(0, m - 1, 0, idx, m - 1);
	  	for (int j = 0; j < level_shops[i].size(); j++) {
	  		update(0, m - 1, 0, mapa[mp(level_shops[i][j].first + acum[i - 1], level_shops[i][j].second)], mapa[mp(level_shops[i][j].first + acum[i - 1], level_shops[i][j].second)], dp[i] + shops[level_shops[i][j].second].second.second);
		}
		idx = (lower_bound(all(A_2), acum[i - 1]) - A_2.begin());
	  	ll ans = query(0, m - 1, 0, idx, m - 1), mini = INF;
	  	for (int j = 0; j < level_shops[i].size(); j++) {
	  		mini = min(mini, shops[level_shops[i][j].second].second.second);
	  		update(0, m - 1, 0, mapa[mp(level_shops[i][j].first + acum[i - 1], level_shops[i][j].second)], mapa[mp(level_shops[i][j].first + acum[i - 1], level_shops[i][j].second)], dp[i] + shops[level_shops[i][j].second].second.second);
		}
		dp[i] = min(dp[i], ans + mini);
	  }
	  if (corta || dp[n] >= INF) {
	  	cout << "-1\n";
	  }
	  else cout << dp[n] << "\n";
  }
}
