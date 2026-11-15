#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, resp;
pair<ll, ll> a[MaxN];
priority_queue<pair<ll, ll> > Maxi, Mini;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    Maxi.push(mp(a[i].first, i));
    Mini.push(mp(-a[i].second, i));
  }
  pair<ll, ll> a = Mini.top(), b = Maxi.top();
  if (a.second == b.second) {
    Mini.pop();
    Maxi.pop();
    a = Mini.top(), b = Maxi.top();
    resp = ((-a.first) - b.first);
  }
  else {
    Mini.pop();
    Maxi.pop();
    pair<ll, ll> a_2 = Mini.top(), b_2 = Maxi.top();
    resp = max(((-a.first) - b_2.first), ((-a_2.first) - b.first));
  }
  resp = max(resp, 0LL);
  cout << resp << "\n";
}

