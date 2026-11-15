#include <bits/stdc++.h>

using namespace std;

#define pt first
#define rp second

  int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string s;
    cin >> n >> s >> m;

    vector<int> R(n + 1, 0);
    vector<int> C(n + 1, 0);
    if (s[n - 1] != 'b') {
      R[n - 1] = 1;

      if (s[n - 1] == '?') {
        C[n - 1] = 1;
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] != 'b') {
        R[i] = 1;
        if (m == 1) {
          R[i] += R[i + 1];
        }
        else if (s[i + 1] != 'a') {
          R[i] += 1 + R[i + 2];
        }

        if (s[i] == '?') {
          C[i] = 1;
        }
      }
      C[i] += C[i + 1];
    }

    auto Pos = [&](int i) {
      return R[i] >= m;
    };
    auto Cost = [&](int i) {
      return C[i] - C[i + m];
    };
    
    vector<pair<int, int>> dp(n + 1, pair<int, int>(0, 0));
    for (int i = 0; i < n; i++) {
      if (dp[i + 1].pt < dp[i].pt) {
        dp[i + 1] = dp[i];
      }
      else if(dp[i + 1].pt == dp[i].pt) {
        dp[i + 1].rp = min(dp[i + 1].rp, dp[i].rp);
      }

      if (Pos(i)) {
        if (dp[i + m].pt < dp[i].pt + 1) {
          dp[i + m] = make_pair(dp[i].pt + 1, dp[i].rp + Cost(i));
        }
        else if (dp[i + m].pt == dp[i].pt + 1) {
          dp[i + m].rp = min(dp[i + m].rp, dp[i].rp + Cost(i));
        }
      }
    }

    cout << dp[n].rp << "\n";
  }
