/**

   * Made by:    Diego Briaares
   * At:   23.10.2021 14:38:59
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

long long P = 1000003;
long long MOD = (long long)1e9 + 7;

	int main () {
		optimize();
		string a, b;
		while (cin >> a) {
   			cin >> b;
   			int k;
   			cin >> k;
   			int n = (int)a.size();
   			vector<long long> pot(k + 1);
   			pot[0] = 1;
   			for (int i = 1; i <= k; i++) {
   				pot[i] = pot[i - 1] * P;
   				pot[i] %= MOD;
   			}
   			long long H = 0;
   			for (int i = 0; i < k; i++) {
   				H += ((long long)(a[i] - 'a') * pot[k - i - 1]);
   				H %= MOD;
   			}
   			set<long long> S;
   			S.insert(H);
   			for (int i = k; i < n; i++) {
   				H -= ((long long)(a[i - k] - 'a') * pot[k - 1]) % MOD;
   				H += MOD;
   				H %= MOD;
   				H *= P;
   				H += (long long)a[i] - 'a';
   				H %= MOD;
   				S.insert(H);
   			}
   			H = 0;
   			for (int i = 0; i < k; i++) {
   				H += ((long long)(b[i] - 'a') * pot[k - i - 1]);
   				H %= MOD;
   			}
   			bool ok = false;
   			if (S.find(H) != S.end()) ok = true;
   			for (int i = k; i < n; i++) {
   				H -= ((long long)(b[i - k] - 'a') * pot[k - 1]) % MOD;
   				H += MOD;
   				H %= MOD;
   				H *= P;
   				H += (long long)b[i] - 'a';
   				H %= MOD;
	   			if (S.find(H) != S.end()) ok = true;
   			}
   			if (ok) cout << "yes\n";
   			else cout << "no\n";
		}
	}