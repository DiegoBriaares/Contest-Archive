/**

   * Made by:    Diego Briaares
   * At:   13.02.2021 13:03:14
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int n, m;
long double p[201][201];
long double ans[201][201];
long double temp[201][201];

void multiply_odd () {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			long double sum = 0;
			for (int r = 1; r <= n; r++) {
				sum += ans[r][j] * p[i][r];
			}
			temp[i][j] = sum;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans[i][j] = temp[i][j];
		}
	}
}
void multiply_even () {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			long double sum = 0;
			for (int r = 1; r <= n; r++) {
				sum += ans[i][r] * ans[r][j];
			}
			temp[i][j] = sum;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans[i][j] = temp[i][j];
		}
	}
}

void power(int e) {
	if (e == 0) return;
	if (e & 1) {
		multiply_odd();
		power(e - 1);
	}
	else {
		multiply_even();
		power(e / 2);
	}
}

	int main () {
		optimize();
		cin >> n >> m;
		for (int i = 1; i <= n; i++)	{
			for (int j = 1; j <= n; j++) {
				cin >> p[i][j];
				ans[i][j] = p[i][j];
			}
		}
		power(m - 1);
		for (int i = 1; i <= n; i++) cout << fixed << setprecision(4) << ans[1][i] << "\n";
	}