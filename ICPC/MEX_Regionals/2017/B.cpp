/**

   * author:    Diego Briaares
   * At:   01.04.2022 19:12:34
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		string s;
		auto vo = [&] (char c) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
			return false;
		};
		while (cin >> s) {
			int n = s.size();
			int vs = 0;
			bool z = false;
			for (int i = 0; i < n; i++)	{
				if (vo(s[i])) {
					vs++;
				}
			}
			if (vs == 0) {
				cout << "1\n";
				continue;
			}
			int l = 0, r = n - 1, rev = 0, ways = 1;
			while (l <= r) {
				if (vo(s[l]) && vo(s[r])) {
					if (!rev) {
						l++;
					}
					else {
						r--;
					}
					vs--;
					rev = !rev;
					continue;
				}
				if (!rev && !vo(s[l])) {
					z = true;
					break;
				}
				if (rev && !vo(s[r])) {
					z = true;
					break;
				}
				if (vs == 1) {
					ways = r - l + 1;
					break;
				}
				if (!rev) {
					if (!vo(s[r])) {
						r--;
						continue;
					}
				}
				else {
					if (!vo(s[l])) {
						l++;
						continue;
					}
				}
			}
			if (z) {
				ways = 0;
			}
			cout << ways << "\n";
		}
	}