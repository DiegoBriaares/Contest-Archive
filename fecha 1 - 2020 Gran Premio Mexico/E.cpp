/**

   * Made by:    Diego Briaares
   * At:   16.02.2021 23:35:56
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

bool criba[(int) 1e7 + 1];
	int main () {
		//optimize();
		set<int> primes;
		for (int i = 2; i < 1e7 + 1;) {
			if (!criba[i]) {
				for (int j = i + i; j < 1e7 + 1 ; j += i) {
					criba[j] = true;
				}
				primes.insert(i);
			}
			if (i == 2) i++;
			else i += 2;
		}
		string s;
		cin >> s;
		if (s.size() < 3) {
			cout << "Bob lies\n";
			return 0;
		}
		vector<int> order(s.size()), vals(s.size());
		iota(order.begin(), order.end(), 1);
		long long ans = 1e15;
		do
		{
			for (int i = 0; i < order.size(); i++) vals[order[i] - 1] = s[i] - '0';
			auto get = [&] (int x, int y) {
				if (vals[x] == 0) return 0LL;
				long long sum = 0, p = 1;
				while (y >= x) {
					sum += vals[y] * p;
					p *= 10;
					y--;
				}
				return sum;
			};
			for (int i = 0; i < vals.size(); i++) {
				for (int j = i + 1; j < vals.size() - 1; j++) {
					long long x, y, z;
					x = get(0, i);
					y = get(i + 1, j);
					z = get(j + 1, vals.size() - 1);
					if (primes.find(x) == primes.end()) continue;
					if (primes.find(y) == primes.end()) continue;
					if (primes.find(z) == primes.end()) continue;
					ans = min(ans, (long long) x * y * z);
				}
			}
		} while (next_permutation(order.begin(), order.end()));
		if (ans == 1e15) {
			cout << "Bob lies\n";			
		}
		else cout << ans << "\n";
	}