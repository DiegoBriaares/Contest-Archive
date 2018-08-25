#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n;
string s;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    bool ok = true;
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
      if (s[i] != 'a') {
        if (s[j] != 'a') {
          if (s[i] - 1 == s[j] - 1) continue;
        }
        if (s[j] != 'z') {
          if (s[i] - 1 == s[j] + 1) continue;
        }
      }
      if (s[i] != 'z') {
        if (s[j] != 'a') {
          if (s[i] + 1 == s[j] - 1) continue;
        }
        if (s[j] != 'z') {
          if (s[i] + 1 == s[j] + 1) continue;
        }
      }
      ok = false;
      cout << "NO\n";
      break;
    }
    if (ok) cout << "YES\n";
  }

}

