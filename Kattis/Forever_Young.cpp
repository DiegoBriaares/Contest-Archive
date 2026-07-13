#include <bits/stdc++.h>

using namespace std;

#define L 100000
#define L2 10000
#define ll long long int

ll l;

string tostr(ll n) {
  string S = "";
  while (n > 0) {
    S += (char) ((n % 10LL) + '0');
    n /= 10LL;
  }
  reverse(S.begin(), S.end());
  return S;
}

bool valid_base(ll b, ll a) {
  string N = "";
  while (a > 0) {
    ll d = (a % b);
    if (d > 9) {
      return false;
    }
    N += (char) (d + '0');
    a /= b;
  }

  reverse(N.begin(), N.end());
  return tostr(l).size() < N.size() || (tostr(l).size() == N.size() && tostr(l) <= N);
}



int invalid_age(ll b, ll a) {
  ll p = 1;
  string l_ = tostr(l);
  reverse(l_.begin(), l_.end());

  for (int i = 0; i < l_.size(); i++) {
    if (l_[i] != '0' && a / ((ll)(l_[i] - '0')) < p) {
      return -1;
    }
    a -= ((ll)(l_[i] - '0') * p);
    if ((i + 1 < l_.size() && a / b < p) || a < 0) {
      return -1;
    }
    p *= b;
  }

  if (a > 0) {
    return 1;
  }
  else {
    return 0;
  }
}

  int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a;
    cin >> a >> l;
    
    ll B = 10;

    for (int b = 11; b <= L; b++) {
      if (valid_base(b, a)) {
        B = b;
      }
    }

    while (l < L2) {
      ll in = L, fin = a;
      ll last = -1;
      while (in <= fin) {
        ll mid = (in + fin) >> 1;
        if (!invalid_age(mid, a)) {
          last = mid;
          break;
        }
        else if (invalid_age(mid, a) > 0) {
          in = mid + 1;
        }
        else {
          fin = mid - 1;
        }
      }
      if (last != -1) {
        B = max(B, last);
        break;
      }
      l++;
    }
    
    cout << B << "\n";
  }
