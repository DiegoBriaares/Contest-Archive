#include "tiling.h"
#include <bits/stdc++.h>

using namespace std;

struct cmpTL {
  bool operator() (pair<int, int> x, pair<int, int> y) const {
    if (x.first < y.first) {
      return true;
    }
    else if (x.first == y.first) {
      return x.second < y.second;
    }
    else {
      return false;
    }
  }
};

struct cmpTR {
  bool operator() (pair<int, int> x, pair<int, int> y) const {
    if (x.first < y.first) {
      return true;
    }
    else if (x.first == y.first) {
      return x.second > y.second;
    }
    else {
      return false;
    }
  }
};

struct cmpBL {
  bool operator() (pair<int, int> x, pair<int, int> y) const {
    if (x.first > y.first) {
      return true;
    }
    else if (x.first == y.first) {
      return x.second < y.second;
    }
    else {
      return false;
    }
  }
};

struct cmpBR {
  bool operator() (pair<int, int> x, pair<int, int> y) const {
    if (x.first > y.first) {
      return true;
    }
    else if (x.first == y.first) {
      return x.second > y.second;
    }
    else {
      return false;
    }
  }
};

set<pair<int, int>, cmpTL> STL;
set<pair<int, int>, cmpTR> STR;
set<pair<int, int>, cmpBL> SBL;
set<pair<int, int>, cmpBR> SBR;
map<vector<int>, int> MP;
int to[(1 << 4)];

void init(int N, int M) {
  for (int i = 0; i < 2 * N; i++) {
    for (int j = 0; j < 2 * M; j++) {
      if ((i & 1) || (j & 1) ) {
        continue;
      }
      STL.insert(make_pair(i, j));
      STR.insert(make_pair(i, j));
      SBL.insert(make_pair(i, j));
      SBR.insert(make_pair(i, j));
    }
  }
  
  for (int m = 0; m < (1 << 4) - 1; m++) {
    vector<int> cfg(4);
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
      cfg[i] = (int)((m & (1 << i)) > 0);
      
      if (cfg[i]) {
        cnt += 1;
      }
    }

    MP[cfg] = m;

    if (cnt == 0) {
      to[m] = 0;
    }
    else if (cnt == 1) {
       if (m & (1 << 0)) {
        to[m] = 0;
      }
      else if (m & (1 << 1)) {
        to[m] = 1;
      }
      else if (m & (1 << 2)) {
        to[m] = 3;
      }
      else if (m & (1 << 3)) {
        to[m] = 2;
      }     
    }
    else if (cnt == 2) {
      if ((m & (1 << 0)) && (m & (1 << 1))) {
        to[m] = 0;
      }
      else if ((m & (1 << 1)) && (m & (1 << 3))) {
        to[m] = 1;
      }
      else if ((m & (1 << 2)) && (m & (1 << 3))) {
        to[m] = 2;
      }
      else if ((m & (1 << 0)) && (m & (1 << 2))) {
        to[m] = 3;
      }
      else {
        if (m & (1 << 0)) {
          to[m] = 1;
        }
        if (m & (1 << 1)) {
          to[m] = 0;
        }
      }
    }
    else {
      if (!(m & (1 << 0))) {
        to[m] = 2;
      }
      else if (!(m & (1 << 1))) {
        to[m] = 3;
      }
      else if (!(m & (1 << 3))) {
        to[m] = 0;
      }
      else if (!(m & (1 << 2))) {
        to[m] = 1;
      }
    }
  }
}

pair<int, int> receive_block(int TL, int TR, int BL, int BR) {
  vector<int> cfg(4);
  cfg[0] = TL;
  cfg[1] = TR;
  cfg[2] = BL;
  cfg[3] = BR;
  
  pair<int, int> it;
  if (to[MP[cfg]] == 0) {
    it = *STL.begin();
  }
  else if (to[MP[cfg]] == 1) {
    it = *STR.begin();
  }
  else if (to[MP[cfg]] == 2) {
    it = *SBR.begin();
  }
  else if (to[MP[cfg]] == 3){
    it = *SBL.begin();
  }

  STL.erase(STL.find(it));
  STR.erase(STR.find(it));
  SBL.erase(SBL.find(it));
  SBR.erase(SBR.find(it));

return it;
}
