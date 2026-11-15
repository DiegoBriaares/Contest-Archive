#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, k, s, sum, l;
ll resp[MaxN];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> s;
  l = 1;
  if (k > s) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 1; i <= k; i++) {
    if (sum + n - 1 + (k - i) >= s) {
      ll j;
      if (l == 1) {
        j = (1 + (s - sum - (k - i)));
      }
      else {
        j = (n - (s - sum - (k - i)));
      }
      resp[i] = j;
      bool who = false;
      for (int it = i + 1; it <= k; it++) {
        if (!who) resp[it] = j + 1, who = true;
        else {
          who = false;
          resp[it] = j;
        }
      }
      cout << "YES\n";
      for (int it = 1; it <= k; it++) {
        if (resp[it] > n) resp[it] -= 2;
        cout << resp[it] << " ";
      }
      return 0;
    }
    else {
      sum += (n - 1);
      if (l == 1) resp[i] = n;
      else resp[i] = 1;
      l = resp[i];
    }
  }
  cout << "NO\n";
}
