#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 301002;

ll n;
string s, t;
vector<ll> resp;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> s >> t;
  if (s == t) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      for (int j = i + 1; j < n; j++) {
        if (s[j] == t[i]) {
          j--;
          while(j >= i) {
            swap(s[j], s[j + 1]);
            resp.push_back(j + 1);
            j--;
          }
          break;
        }
      }
    }
  }
  if (s != t) {
    cout << "-1\n";
  }
  else {
    cout << resp.size() << "\n";
    for (int i = 0; i < resp.size(); i++) {
      cout << resp[i] << " ";
    }
    cout << "\n";
  }
}
