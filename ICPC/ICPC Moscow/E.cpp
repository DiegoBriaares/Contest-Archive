/**

   * Made by:    Diego Briaares
   * At:   05.10.2021 03:31:41
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

const int MAX = 200001;

int bit[MAX];

void update(int i, int x) {
	while (i < MAX) {
		bit[i] += x;
		i += (i & -i);
	}
}

int query(int i) {
	int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= (i & -i);
	}
	return s;
}

int bitLH[MAX];

void updateLH(int i, int x) {
	while (i < MAX) {
		bitLH[i] += x;
		i += (i & -i);
	}
}

int queryLH(int i) {
	int s = 0;
	while (i > 0) {
		s += bitLH[i];
		i -= (i & -i);
	}
	return s;
}

int bitRH[MAX];

void updateRH(int i, int x) {
	while (i < MAX) {
		bitRH[i] += x;
		i += (i & -i);
	}
}

int queryRH(int i) {
	int s = 0;
	while (i > 0) {
		s += bitRH[i];
		i -= (i & -i);
	}
	return s;
}

int bitLV[MAX];

void updateLV(int i, int x) {
	while (i < MAX) {
		bitLV[i] += x;
		i += (i & -i);
	}
}

int queryLV(int i) {
	int s = 0;
	while (i > 0) {
		s += bitLV[i];
		i -= (i & -i);
	}
	return s;
}

int bitRV[MAX];

void updateRV(int i, int x) {
	while (i < MAX) {
		bitRV[i] += x;
		i += (i & -i);
	}
}

int queryRV(int i) {
	int s = 0;
	while (i > 0) {
		s += bitRV[i];
		i -= (i & -i);
	}
	return s;
}



	int main () {
		optimize();
		int n, k;
		cin >> n >> k;
		vector<long long> A(n + 1, 0);
		vector<long long> LH(n + 1, 0), RH(n + 1, 0);
		vector<long long> LV(n + 1, 0), RV(n + 1, 0);
		while (k--) {
			char op;
			int x1, x2;
			cin >> op >> x1 >> x2;
			if (op == 'R') {
				update(x1, 1);
				update(x2 + 1, -1);
			}
			if (op == 'D') {
				update(x1, -1);
				update(x2 + 1, 1);
			}
			if (op == 'H') {
				int m = (x2 - x1) / 2;
				if (x1 + m == x2 - m) {
					A[x1 + m] += m + 1;
					m--;
				}
				LH[x1 + m] += m + 1;
				RH[x2 - m] += m + 1;
				updateLH(x1, 1);
				updateLH(x1 + m + 1, -1);
				updateRH(x2 - m, 1);
				updateRH(x2 + 1, -1);

			}
			if (op == 'V') {
				int m = (x2 - x1) / 2;
				if (x1 + m == x2 - m) {
					A[x1 + m] -= (m + 1);
					m--;
				}
				LV[x1 + m] += m + 1;
				RV[x2 - m] += m + 1;
				updateLV(x1, 1);
				updateLV(x1 + m + 1, -1);
				updateRV(x2 - m, 1);
				updateRV(x2 + 1, -1);
			}
		}
		long long s = 0;
		for (int i = 1; i <= n; i++) {
			s = max(s, 0LL);
			s += RH[i];
			A[i] += s;
			s -= queryRH(i);
		}
		s = 0;
		for (int i = n; i >= 1; i--) {
			s = max(s, 0LL);
			s += LH[i];
			A[i] += s;
			s -= queryLH(i);
		}
		s = 0;
		for (int i = 1; i <= n; i++) {
			s = max(s, 0LL);
			s += RV[i];
			A[i] -= s;
			s -= queryRV(i);
		}
		s = 0;
		for (int i = n; i >= 1; i--) {
			s = max(s, 0LL);
			s += LV[i];
			A[i] -= s;
			s -= queryLV(i);
		}
		for (int i = 1; i <= n; i++) {
			cout << (long long) A[i] + query(i) << "\n";
		}
	}
