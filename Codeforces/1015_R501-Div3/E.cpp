#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 202;

ll n, c;
char m[MaxN][MaxN];
vector<pair<ll, ll> > resp;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < c; j++) {
      cin >> m[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < c; j++) {
      int cont = 0;
      for (int it = 0; it < 4; it++) {
        int x = i + dx[it];
        int y = j + dy[it];
        if (0 <= x && 0 <= y && x < n && y < c) cont++;
      }
      if (cont == 4) {
        m[i][j] = '*';
        for (int it = 0; it < 4; it++) {
          int x = i + dx[it];
          int y = j + dy[it];
          m[x][y] = '*';
        }
        resp.push_back(make_pair(i, j));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < c; j++) {
      if (m[i][j] != '*') {
        cout << "-1\n";
        return 0;
      }
    }
  }
  cout << resp.size() << "\n";
  for (int i = 0; i < resp.size(); i++) {
    cout << resp[i].first + 1 << " " << resp[i].second + 1 << " 1 \n"; 
  }
}
