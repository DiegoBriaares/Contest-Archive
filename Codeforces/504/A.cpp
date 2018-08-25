#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, m;
string s, t;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  cin >> s >> t;
  int idx;
  bool ast = false;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      ast = true;
      idx = i;
    }
  }
  if (!ast) {
    if (s == t) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
    return 0;
  }
  if (n > m + 1) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 0; i < idx; i++) {
    if (s[i] != t[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  for (int i = n - 1, j = m - 1; i > idx; i--, j--) {
    if (s[i] != t[j]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}
