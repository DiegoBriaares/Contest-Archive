/**

   * author:    Diego Briaares
   * At:   08.10.2022 12:28:53
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int n;
		cin >> n;
		string s;
		cin >> s;
		if (n == 1) {
			cout << "0\n";
			return 0;
		}
		map<char, int> M;
		for (int i = 0; i < n; i++)	{
			if (i == 0) {
				if (s[i] == s[i + 1]) {
					M[s[i]]++;
				}
			}
			else {
				if (s[i] != s[i - 1]) {
					if (i == n - 1 || s[i] != s[i + 1]) {
						continue;
					}
					else {
						M[s[i]]++;
					}
				}
				else {
					M[s[i]]++;
				}
			}
		}
		cout << M['a'] << "\n";
	}