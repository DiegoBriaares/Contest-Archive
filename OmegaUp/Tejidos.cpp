#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> acc_p(vector<int> &L, vector<int> &R) {
  vector<int> ret(N, 0);
  int skip = false;
  for (int i = 0; i < N; i++) {
    if (i > 0 && !skip) {
      ret[i] = ret[i - 1];
    }
    skip = false;
    if (L[i] < 0) {
      ret[i] = 0;
    }
    else {
      if (L[i] == R[i]) {
        if (L[i] == 1) {
          ret[i] = 1;
        }
        else {
          if (ret[i] && L[i] == L[i - 1] + 1) {
            ret[i]++;
          }
          else {
            ret[i] = 0;
          }
        }
      }
      else {
        if (ret[i] && L[i] > L[i - 1] && R[i] > R[i - 1]) {
          ret[i]++;
          skip = true;
        }
        else {
          ret[i] = 0;
        }
      }
    }
  }
  return ret;
}

vector<int> acc_w(vector<int> &a) {
  vector<int> ret(N);
  for (int i = 0; i < N; i++) {
    if (i > 0) {
      ret[i] = ret[i - 1];
    }

    if (a[i]) {
      if (ret[i] < 0) {
        ret[i] = 0;
      } 

      ret[i] += 1;
    }
    else {
      if (ret[i] > 0) {
        ret[i] = 0;
      }

      ret[i] -= 1;
    }
  }

  return ret;
}

  int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    vector<vector<int>> M(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        char c;
        cin >> c;
        if (c == 'O') {
          M[i][j] = 1;
        }
      }
    }

    vector<vector<int>> L, R;
    vector<int> row;
    for (int i = 0; i < N; i++) {
      row.clear();
      for (int j = 0; j < N; j++) {
        row.push_back(M[i][j]);
      }

      L.push_back(acc_w(row));
      reverse(row.begin(), row.end());
      R.push_back(acc_w(row));
      reverse(R.back().begin(), R.back().end());
    }

    int mx = 0;
    vector<int> U, D;
    vector<int> Lcol, Rcol;
    for (int j = 0; j < N; j++) {
      Lcol.clear();
      Rcol.clear();
      for (int i = 0; i < N; i++) {
        Lcol.push_back(L[i][j]);
        Rcol.push_back(R[i][j]);
      }
      
      U = acc_p(Lcol, Rcol);
      reverse(Lcol.begin(), Lcol.end());
      reverse(Rcol.begin(), Rcol.end());
      D = acc_p(Lcol, Rcol);
      reverse(D.begin(), D.end());
      for (int i = 0; i < N; i++) {
        if (U[i] == D[i]) {
        
        bool ok = true;
          for (int k = 1; k < U[i]; k++) {
            int Lb = j - L[i - k][j];
            int Rb = j + R[i - k][j];
            if (Lb >= 0) {
              if (L[i - 1][j] + 1 > -(L[i - k][Lb]) + L[i - k][j]) {
                ok = false;
              }
              if (L[i + 1][j] + 1 > -(L[i + k][Lb]) + L[i + k][j]) {
                ok = false;
              }
            }
            if (Rb < N) {
              if (R[i - 1][j] + 1 > -(R[i - k][Rb]) + R[i - k][j]) {
                ok = false;
              }
              if (R[i + 1][j] + 1 > -(R[i + k][Rb]) + R[i + k][j]) {
                ok = false;
              }
            }
          }

          if (ok) {
            mx = max(mx, U[i] + D[i] - 1);
          }
        }
      }
    }
    if (mx == 1) {
      mx = 0;
    }

    cout << (mx ? mx : -1) << "\n";

    return 0;
  }
