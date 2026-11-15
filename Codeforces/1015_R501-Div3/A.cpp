#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, m;
ll h[MaxN];
vector<ll> resp;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    while(l <= r) {
      h[l]++;
      l++;
    }
  }
  for(int i = 1; i <= m; i++) {
    if (!h[i]) {
      resp.push_back(i);
    }
  }
  cout << resp.size() << "\n";
  for (int i = 0; i < resp.size(); i++) {
    cout << resp[i] << " ";
  }
  cout << "\n";
}


