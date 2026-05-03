/**

   * author:    Diego Briaares
   * At:   08.10.2022 13:51:52
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
		multiset<int> av;
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= 13; j++) {
				av.insert(j);
			}
		}
		int sj = 0, sm = 0;
		for (int i = 0; i < 2; i++)	{
			int x;
			cin >> x;
			av.erase(av.find(x));
			x = min(x, 10);
			sj += x;
		}
		for (int i = 0; i < 2; i++)	{
			int x;
			cin >> x;
			av.erase(av.find(x));
			x = min(x, 10);
			sm += x;
		}
		while (n--) {
			int x;
			cin >> x;
			av.erase(av.find(x));
			x = min(x, 10);
			sj += x;
			sm += x;
		}

		while (!av.empty() && min(10, *av.begin()) + sm <= 23) {
			int cur = min(10, *av.begin());
			if (cur + sm == 23) {
				cout << *av.begin() << "\n";
				return 0;
			}
			if (cur + sm <= 23 && cur + sj > 23) {
				cout << *av.begin() << "\n";
				return 0;
			}
			av.erase(av.begin());
		}
		cout << "-1\n";
	}