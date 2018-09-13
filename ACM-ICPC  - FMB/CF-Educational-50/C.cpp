#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll comb[20][4];

ll f(ll x) {
 ll ans = 0;
 int dig_nz = 0;
 vector<int> num;
 while (x > 0) {
    ll dig = (x % 10LL);
    x /= 10LL;
    if (dig) dig_nz++;
    num.push_back(dig);
 }
 int it = 0;
 while (dig_nz > 3 && it < num.size()) {
    if (num[it])dig_nz--;
    it++;
 }
 for (int i = it; i < num.size() && dig_nz > 0; i++) {
    if (num[i]) {
        if (dig_nz == 3) {
            ans += num[i];
            ans += 9LL * (ll)i;
        }
        else if (dig_nz == 2) {
            ans += num[i];
            ans += (num[i] - 1) * (9LL * (ll)i);
            ans += comb[i][2] * 9LL * 9LL + comb[i][1] * 9LL;
        }
        else {
            ans += num[i];
            ans += (num[i] - 1) * (9LL * (ll)i);
            ans += (num[i] - 1) * comb[i][2] * 9LL * 9LL;
            ans += comb[i][3] * 9LL * 9LL * 9LL + comb[i][2] * 9LL * 9LL + comb[i][1] * 9LL;
        }
        dig_nz--;
    }
 }
 return ans;
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll q;
  cin >> q;
  for (int i = 1;i < 20; i++) comb[i][1] = i;
  for (int i = 1;i<20;i++) comb[i][2] = (i * (i - 1)) / 2LL;
  for (int i = 1;i < 20; i++) comb[i][3] = (i * (i - 1) * (i - 2)) / 6LL;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    cout << f(r) - f(l - 1) << "\n";
  }
}
