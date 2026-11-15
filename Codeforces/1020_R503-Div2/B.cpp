#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, k;
ll p[MaxN];
bool hole[MaxN];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    int student = i;
    for (int j = 1; j <= n; j++) {
      hole[j] = false;
    }
    while (!hole[student]) {
      hole[student] = true;
      student = p[student];
    }
    cout << student << " ";
  }
  cout << "\n";
}

