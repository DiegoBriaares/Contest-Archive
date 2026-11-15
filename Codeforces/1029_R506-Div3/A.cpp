#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, k;
string s, res;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  cin >> s;
  res = s;
  for (int it = 1; it < k; it++) {
    bool added =  false;
    for (int i = res.size() - n + 1; i < res.size(); i++) {
      bool ok = true;
      for (int j = 0; i + j < res.size(); j++) {
        if (s[j] != res[i + j]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        for (int j = 0; j < n; j++) {
          if (i + j < res.size()) continue;
          res += s[j];
        }
        added = true;
        break;
      }
    }
    if (!added) {
      res += s;
    }
  }
  cout << res << "\n";
}

