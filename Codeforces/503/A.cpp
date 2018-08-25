#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, h, a, b, q;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> h >> a >> b >> q;
  while (q--) {
    int t_a, f_a, t_b, f_b;
    cin >> t_a >> f_a >> t_b >> f_b;
    if (t_a == t_b) {
      cout << abs(f_a - f_b) << "\n";
    }
    else {
      if (f_a < a || f_a > b) {
        if (abs(a - f_a) + abs(a - f_b) < abs(b - f_a) + abs(b - f_b)) {
          cout << abs(a - f_a) + abs(a - f_b) + abs(t_a - t_b) << "\n";
        }
        else {
          cout << abs(b - f_a) + abs(b - f_b) + abs(t_a - t_b) << "\n";
        }
      }
      else {
        cout << abs(f_a - f_b) + abs(t_a - t_b) << "\n";
      }
    }
  }
}

