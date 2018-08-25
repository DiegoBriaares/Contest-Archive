#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n, k;
string s;
vector<pair<int, char> > resp;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  cin >> s;
  k /= 2;
  int op = k, cl = k;
  for (int i = 0; i < n; i++ ){
    if (s[i] == '(' && op) {
      op--;
      resp.push_back(mp(i, '('));
    }
    if (s[i] == ')' && cl) {
      cl--;
      resp.push_back(mp(i, ')'));
    }
  }
  sort(all(resp));
  for (int i = 0; i < resp.size(); i++) {
    cout << resp[i].second;
  }
  cout << "\n";
}

