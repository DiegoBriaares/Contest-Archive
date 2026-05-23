#include <iostream>
#include <vector>

using namespace std;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  int N;
  N = (int)s.size();

  vector<int> O(N);
  vector<int> E(N);
  int m, r;
  int k;

  /* 
    Compute maximum lenghts for odd-length palindromes. 
  */
  m = r = 0;
  O[0] = 0;
  for (int i = 1; i < N; i++) {
    if (r > i) {
       O[i] = min(O[2 * m - i], r - i);
    }
    else {
      O[i] = 0;
    }

    k = 1;
    while (i - O[i] - k >= 0 && 
           i + O[i] + k < N && 
           s[i - O[i] - k] == s[i + O[i] + k]) {
      k++;
    }
    O[i] += k - 1;

    if (i + O[i] > r) {
      m = i;
      r = i + O[i];
    }
  }

  /* 
    Compute maximum lenghts for even-length palindromes. 
  */
  m = r = 0;
  E[0] = 0;
  for (int i = 1; i < N; i++) {
    if (r > i) {
      E[i] = min(E[2 * m - i], r - i);
    }
    else {
      E[i] = 0;
    }

    k = 1;
    while (i - E[i] - k >= 0 &&
           i + E[i] + k - 1 < N &&
           s[i - E[i] - k] == s[i + E[i] + k - 1]) {
      k++;
    }
    E[i] += k - 1;

    if (i + E[i] - 1 > r) {
      m = i;
      r = i + E[i] - 1;
    }
  }

  for (int i = 0; i < N - 1; i++) {
    cout << 2 * O[i] + 1 << " " << 2 * E[i + 1] << " ";
  }
  cout << 2 * O[N - 1] + 1 << "\n"; 
}
