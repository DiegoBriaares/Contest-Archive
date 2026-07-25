#include <bits/stdc++.h>

using namespace std;

const int MAXT = 1e6;
const int MAXN = 100;

int k, l, m;

int pA, pB, pC;

bool vis[MAXN][MAXN][MAXN][2];
int vA_0, vA_pA;
int vB_0, vB_pB;
int vC_0;


/*
   Returns the magnet at position p after T seconds has passed in a wheel with M rims,
   if cw = 0, the wheel goes clock-wise,
   if cw = 1, the wheel goes counter-clock-wise.
*/
int f(int T, int p, int M, int cw) {
  if (cw == 0) {
    return (p + (T % M)) % M;
  }
  else {
    return (p - (T % M) + M) % M;
  }
}

/* 
   T is seconds it has passed,
   w the current wheel,
   LR = 0 iff ball in left-most position,
   LR = 1 iff ball in right-most position.
*/

int solve(int T, int w, int LR) {
  vA_0 = f(T, 0, k, 0), vA_pA = f(T, pA, k, 0);
  vB_0 = f(T, 0, l, 1), vB_pB = f(T, pB, l, 1);
  vC_0 = f(T, 0, m, 0);

  if (vis[vA_0][vB_0][vC_0][w]) {
    return -1;
  }
  vis[vA_0][vB_0][vC_0][w] = true;

  int t = 0;
  if (w == 0) {
    if (LR == 0) {
      t = solve(T + pA, w, 1);
    }
    else {
      if (vA_pA < vB_0) {
        t = solve(T, 1, 0);
      }
      else {
        t = solve(T + pA, w, 0);
      }
    }
  }
  else {
    if (LR == 0) {
      if (vB_0 < vA_pA) {
        t = solve(T, 0, 1);
      }
      else {
        t = solve(T + pB, w, 1);
      }
    }
    else {
      if (vB_pB < vC_0) {
        t = T + pC;
      }
      else {
        t = solve(T + pB, w, 0);
      }
    }
  }

  return t;
}

  int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> l >> m;

    pA = k >> 1;
    pB = l >> 1;
    pC = m >> 1;

    cout << solve(0, 0, 0) << "\n";

    
  }
