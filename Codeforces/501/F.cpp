#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 202;
const ll MOD = 1000000007;

ll A, C;
string s;
ll n, tam;
bool ans_exist;
ll memo[MaxN][MaxN][MaxN][2];

ll dp(int i, int open, int close, int st) {
  if (i == n) {
    if (st && !close && !open) {
      ans_exist = true;
      return 1;
    }
    return 0;
  }
  if (memo[i][open][close][st] != -1) return memo[i][open][close][st];
  if (!st) {
    memo[i][open][close][st] = 0;
    memo[i][open][close][st] += dp(i + 1, open, close + 1, st) % MOD;
    if (open > 0) {
      memo[i][open][close][st] += dp(i + 1, open - 1, close, st);
      memo[i][open][close][st] %= MOD;
    }
    if (close > 0) {
      memo[i][open][close][st] += dp(i + 1, open, close - 1, st); 
      memo[i][open][close][st] %= MOD;
    }
    if (i + tam <= n) {
      memo[i][open][close][st] += dp(i + tam, open, close + C, true);
      memo[i][open][close][st] %= MOD;
    }
  }
  else {
    memo[i][open][close][st] = dp(i + 1, open, close + 1, st);
    memo[i][open][close][st] %= MOD;
    if (close > 0) {
      memo[i][open][close][st] += dp(i + 1, open, close - 1, st); 
      memo[i][open][close][st] %= MOD;
    }
  }
  return memo[i][open][close][st];
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(memo, -1, sizeof(memo));
  cin >> n;
  n *= 2;
  cin >> s;
  tam = s.size();
  for (int i = 0; i < tam; i++) {
    if (s[i] == '(') {
      C++;
    }
    else {
      if (C > 0) {
        C--;
      }
      else {
        A++;
      }
    }
  }
  cout << "AUX: " << A << " " << C << "\n";
  ll resp = dp(0, A, 0, 0);
  if (ans_exist)cout << resp << "\n";
  else cout << "0\n";
}
