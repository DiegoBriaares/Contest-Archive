/**

   * author:    Diego Briaares
   * At:   08.10.2022 15:21:10
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int n, C;
		cin >> n >> C;
		unordered_map<string, int> M;
		string ans = "";
		int mxx = 0;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < C; j++) {
				if (s[j] == '*') {
					for (int it = 0; it < 26; it++) {
						char old = s[j];
						s[j] = (char) ('a' + it);
						M[s]++;
						int cnt = M[s];
						if (cnt == mxx) {
							if (ans > s) {
								ans = s;
							}
						}
						if (cnt > mxx) {
							mxx = cnt;
							ans = s;
						}
						s[j] = old;
					}
				}
			}
		}
		cout << ans << " " << mxx << "\n";
	}