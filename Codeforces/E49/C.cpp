#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;
const ll MaxL = 11002;

ll n, k;
ll a[MaxL];
ll b[MaxL];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cin >> n;
    vector<ll> valids, resp;
    for (int i = 0; i < n; i++) {
      ll x;
      cin >> x;
      a[x]++;
      if (a[x] == 2 && b[x] < 3) {
        a[x] = 0;
        b[x]++;
        valids.push_back(x);
      }
    }
    sort(all(valids));
    double minimal = MaxN * MaxN;;
    for (int i = 0; i < valids.size(); i++) {
      for (int j = 1; j < 50; j++) {
        double a, b;
        if (i - j >= 0) {
          a = (double)valids[i], b = (double)valids[i - j];
          if ((((double)4 * (a + b) * (a + b)) / (a * b)) < minimal) {
            minimal = (((double)4 * (a + b) * (a + b)) / (a * b));
            resp.clear();
            resp.push_back(valids[i]);
            resp.push_back(valids[i]);
            resp.push_back(valids[i - j]);
            resp.push_back(valids[i - j]);
          }
        }
        if (i + j < valids.size()) {
          a = (double)valids[i], b = (double)valids[i + j];
          if ((((double)4 * (a + b) * (a + b)) / (a * b)) < minimal) {
            minimal = (((double)4 * (a + b) * (a + b)) / (a * b));
            resp.clear();
            resp.push_back(valids[i]);
            resp.push_back(valids[i]);
            resp.push_back(valids[i + j]);
            resp.push_back(valids[i + j]);
          }
        }
      }
    }
    for (int i = 0; i < resp.size(); i++) {
      cout << resp[i] << " ";
    }
    cout << "\n";
  }
}
