#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, k;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  cout << (k / n) + (k % n ? 1 : 0) << "\n";
}
